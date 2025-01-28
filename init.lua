-- Basic Options
-- Configure indentation, color support, and split behavior
vim.opt.expandtab = true           -- Use spaces instead of tabs
vim.opt.tabstop = 2                -- Number of spaces for a tab
vim.opt.shiftwidth = 2             -- Number of spaces for autoindent
vim.opt.softtabstop = 2            -- Number of spaces for Tab key
vim.opt.smartindent = true         -- Enable smart indentation
vim.opt.termguicolors = true       -- Enable true color support
vim.opt.splitright = true          -- Vertical splits open to the right
vim.opt.wrap = false               -- Disable line wrapping

-- Set Leader Key
vim.g.mapleader = " "             -- Set the leader key to space

-- Keybindings
-- Close the current buffer with <Leader>q
vim.keymap.set('n', '<Leader>q', ':bd!<CR>', { noremap = true, silent = true })

-- Keybinding for Generate assembly and view it
local function gen_asm_and_view_it(cc, cflags)
  local ifname = vim.fn.expand("%")             -- Current file name
  local ofname = vim.fn.expand("%:r") .. ".asm" -- Output file name
  local name = vim.fn.expand("<cword>")         -- Word under cursor
  vim.cmd("w")                                  -- Save current file
  local compile_command = cc .. " -S -masm=intel " .. 
                          "-fno-stack-clash-protection " .. 
                          "-fno-stack-protector " ..
                          "-ffreestanding " ..
                          vim.fn.shellescape(ifname) ..
                          " -DNDEBUG ".. 
                          cflags .. 
                          " -o " .. vim.fn.shellescape(ofname)
  os.execute(compile_command)
  vim.cmd("vsplit " .. ofname)                  -- Open assembly file in a vertical split
  local strs = {"\\.addrsig",
	              "\\.addrsig_sym",
	              "\\.cfi_",
	              "\\.file",
	              "\\.globl",
	              "\\.p2align",
	              "\\.section",
	              "\\.size",
	              "\\.text",
	              "\\.type",
                "\\.Lfunc_end",
                "\\.LFB\\d\\d*:",
                "\\.LFE\\d\\d*:",
                "#"}
  local buf = vim.api.nvim_get_current_buf()
  for i,s in ipairs(strs) do
    vim.cmd("%s/^\\s*".. s ..".*\\n//ge")           -- Remove matched lines
  end
  vim.cmd("w")                                  -- Save cleaned assembly file
  vim.cmd("normal gg0")                        -- Move to the beginning of the file
  local success, err = pcall(function()
    vim.cmd("/" .. name .. ":")               -- Search for the word in the file
  end)
  vim.cmd("normal zt")                         -- Center the match in the window
end
vim.keymap.set('n', '<leader>3', function() gen_asm_and_view_it("clang", "-O3") end, { noremap = true, silent = true })
vim.keymap.set('n', '<leader>2', function() gen_asm_and_view_it("clang", "-O2") end, { noremap = true, silent = true })
vim.keymap.set('n', '<leader>1', function() gen_asm_and_view_it("clang", "-O1") end, { noremap = true, silent = true })
vim.keymap.set('n', '<leader>0', function() gen_asm_and_view_it("clang", "-O0") end, { noremap = true, silent = true })
vim.keymap.set('n', '<leader>#', function() gen_asm_and_view_it("gcc", "-O3") end, { noremap = true, silent = true })
vim.keymap.set('n', '<leader>@', function() gen_asm_and_view_it("gcc", "-O2") end, { noremap = true, silent = true })
vim.keymap.set('n', '<leader>!', function() gen_asm_and_view_it("gcc", "-O1") end, { noremap = true, silent = true })
vim.keymap.set('n', '<leader>)', function() gen_asm_and_view_it("gcc", "-O0") end, { noremap = true, silent = true })


-- Neovide Configuration
if vim.g.neovide then
  vim.g.transparency = 0.94
  vim.g.neovide_transparency = 0.94
  vim.o.guifont = "NovaMono:h14"
end

-- Plugin Management with packer.nvim
local ensure_packer = function()
  local fn = vim.fn
  local install_path = fn.stdpath('data') .. '/site/pack/packer/start/packer.nvim'
  if fn.empty(fn.glob(install_path)) > 0 then
    fn.system({'git', 'clone', '--depth', '1', 'https://github.com/wbthomason/packer.nvim', install_path})
    vim.cmd [[packadd packer.nvim]]
    return true
  end
  return false
end

local packer_bootstrap = ensure_packer()

require('packer').startup(function(use)
  use 'wbthomason/packer.nvim'     -- Package manager
  use {
    'nvim-treesitter/nvim-treesitter',
    run = ':TSUpdate',             -- Treesitter for syntax highlighting
  }
  use 'norcalli/nvim-colorizer.lua' -- Colorizer for color codes highlighting
  use 'neovim/nvim-lspconfig'       -- LSP configuration
  use {
      'maxmx03/solarized.nvim',
      config = function()
        vim.o.background = 'dark'
        ---@type solarized
        local solarized = require('solarized')
        vim.o.termguicolors = true
        vim.o.background = 'dark'
        solarized.setup()
        vim.cmd.colorscheme 'solarized'
      end
  }
  use 'sbdchd/neoformat'            -- Code formatter
  use 'tpope/vim-fugitive'          -- Git integration
  use 'nvim-lualine/lualine.nvim'
  use 'tpope/vim-fugitive'

  if packer_bootstrap then
    require('packer').sync()
  end
end)

-- Treesitter Configuration
require('nvim-treesitter.configs').setup {
  ensure_installed = {"c"},       -- Install C parser
  highlight = {
    enable = true,                 -- Enable Treesitter highlighting
  },
}

-- Colorizer Configuration
require('colorizer').setup({ '*' }, { mode = 'foreground' })

-- LSP Configuration with Clangd
local lspconfig = require('lspconfig')
lspconfig.clangd.setup {
  cmd = { "clangd" },            -- Ensure clangd is installed and in PATH
  filetypes = { "c", "cpp" },
  root_dir = lspconfig.util.root_pattern(".git", "compile_commands.json", "build"),
}

-- Keybindings for LSP
local on_attach = function(client, bufnr)
  local bufopts = { noremap = true, silent = true, buffer = bufnr }
  vim.keymap.set('n', 'gD', vim.lsp.buf.definition, bufopts)
  vim.keymap.set('n', 'K', vim.lsp.buf.hover, bufopts)
  vim.keymap.set('n', 'gd', vim.lsp.buf.implementation, bufopts)
  vim.keymap.set('n', '<C-k>', vim.lsp.buf.signature_help, bufopts)
end
require('lualine').setup {
  options = {
    -- ... your lualine config
    theme = 'solarized'
    -- ... your lualine config
  }
}

