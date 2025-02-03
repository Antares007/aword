-- Basic Options
-- Configure indentation, color support, and split behavior
vim.opt.expandtab = true     -- Use spaces instead of tabs
vim.opt.tabstop = 2          -- Number of spaces for a tab
vim.opt.shiftwidth = 2       -- Number of spaces for autoindent
vim.opt.softtabstop = 2      -- Number of spaces for Tab key
vim.opt.smartindent = true   -- Enable smart indentation
vim.opt.termguicolors = true -- Enable true color support
vim.opt.splitright = true    -- Vertical splits open to the right
vim.opt.wrap = false         -- Disable line wrapping
vim.opt.signcolumn = "yes:1"

-- Set Leader Key
vim.g.mapleader = " " -- Set the leader key to space

if vim.g.neovide then
  vim.g.neovide_scale_factor = vim.g.neovide_scale_factor or 1.0
  vim.keymap.set("n", "<C-=>", function()
    vim.g.neovide_scale_factor = vim.g.neovide_scale_factor + 0.01
  end, { silent = true })
  vim.keymap.set("n", "<C-->", function()
    vim.g.neovide_scale_factor = vim.g.neovide_scale_factor - 0.01
  end, { silent = true })
end

-- Keybindings
-- Close the current buffer with <Leader>q
vim.keymap.set('n', '<Leader>q', ':bd!<CR>', { noremap = true, silent = true })
local run_current_buffer = function()
  local filename = vim.fn.expand("%:t")  -- Get the current file name (e.g., "name.c")
  local extension = vim.fn.expand("%:e") -- Get the file extension (e.g., "c")
  local basename = vim.fn.expand("%:r")  -- Get the file name without extension (e.g., "name")
  local root_dir = vim.fn.getcwd()       -- Get the root directory of the project

  -- Check if a Makefile exists in the root directory
  local makefile_exists = vim.fn.filereadable(root_dir .. "/Makefile") == 1

  if extension == "c" then
    if makefile_exists then
      -- Run `make <basename>.out`
      vim.cmd("w|vsplit term://make -B " .. basename .. ".out && ./" .. basename .. ".out")
    else
      -- Compile and run the C file directly
      vim.cmd("w|vsplit term://gcc " .. filename .. " -o " .. basename .. ".out && ./" .. basename .. ".out")
    end
  elseif extension == "js" then
    -- Run the JavaScript file with Node.js
    vim.cmd("w|vsplit term://node " .. filename)
  elseif extension == "lua" then
    -- Run the JavaScript file with Node.js
    vim.cmd("w|vsplit term://lua " .. filename)
  else
    print("Unsupported file type: " .. extension)
  end
end
vim.keymap.set("n", "<Leader>c", run_current_buffer, { noremap = true, silent = true })

-- Keybinding for Generate assembly and view it
local prefixes_of_lines_to_remove = {
  "\\.addrsig",
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
  "#"
}
local function gen_asm_and_view_it(cc, cflags)
  local ifname = vim.fn.expand("%")             -- Current file name
  local ofname = vim.fn.tempname() .. ".asm" -- Output file name
  local name = vim.fn.expand("<cword>")         -- Word under cursor
  vim.cmd("w")                                  -- Save current file
  local compile_command = cc .. " -S -masm=intel " ..
      "-fno-stack-clash-protection " ..
      "-fno-stack-protector " ..
      "-ffreestanding " ..
      vim.fn.shellescape(ifname) ..
      " -DNDEBUG " ..
      cflags ..
      " -o " .. vim.fn.shellescape(ofname)
  local rez = vim.fn.system(compile_command)
  local exit_code = vim.v.shell_error
  if exit_code ~= 0 then
    vim.notify(rez, vim.log.levels.INFO)
  else
    vim.cmd("vsplit " .. ofname) -- Open assembly file in a vertical split
    for _, s in ipairs(prefixes_of_lines_to_remove) do
      vim.cmd("%s/^\\s*" .. s .. ".*\\n//ge") -- Remove matched lines
    end
    vim.cmd("w")                              -- Save cleaned assembly file
    vim.cmd("normal gg0")                     -- Move to the beginning of the file
    local _, _ = pcall(function()
      vim.cmd("/" .. name .. ":")             -- Search for the word in the file
    end)
    vim.cmd("normal zt")                      -- Center the match in the window
  end
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
    fn.system({ 'git', 'clone', '--depth', '1', 'https://github.com/wbthomason/packer.nvim', install_path })
    vim.cmd [[packadd packer.nvim]]
    return true
  end
  return false
end

local packer_bootstrap = ensure_packer()

require('packer').startup(function(use)
  use 'wbthomason/packer.nvim' -- Package manager
  use {
    'nvim-treesitter/nvim-treesitter',
    run = ':TSUpdate',              -- Treesitter for syntax highlighting
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
      solarized.setup({})
      vim.cmd.colorscheme 'solarized'
    end
  }
  use 'sbdchd/neoformat'   -- Code formatter
  use 'tpope/vim-fugitive' -- Git integration
  use 'nvim-lualine/lualine.nvim'
  use 'tpope/vim-fugitive'

  if packer_bootstrap then
    require('packer').sync()
  end
end)

-- Treesitter Configuration
require('nvim-treesitter.configs')
    .setup {
      ensure_installed = { "c", "lua" }, -- Install C parser
      highlight = {
        enable = true,                   -- Enable Treesitter highlighting
      },
    }

-- Colorizer Configuration
require('colorizer').setup({ '*' }, { mode = 'foreground' })

-- LSP Configuration with Clangd
-- Keybindings for LSP


local on_attach = function(client, bufnr)
  local bufopts = { noremap = true, silent = true, buffer = bufnr }
  vim.keymap.set('n', 'gd', vim.lsp.buf.declaration, bufopts)
  vim.keymap.set('n', 'K', vim.lsp.buf.hover, bufopts)
  vim.keymap.set('n', 'gD', vim.lsp.buf.implementation, bufopts)
  vim.keymap.set('n', '<C-k>', vim.lsp.buf.signature_help, bufopts)
  local lsp_actions = {}
  for key in pairs(vim.lsp.buf) do
    table.insert(lsp_actions, key)
  end
  table.sort(lsp_actions)
  local ShowLspMenu = function()
    vim.ui.select(lsp_actions, {
      prompt = "Select LSP Action:",
      format_item = function(item)
        return item:gsub("_", " "):gsub("^%l", string.upper) -- Format menu items (e.g., "code_action" -> "Code action")
      end,
    }, function(choice)
      if choice then
        -- Execute the corresponding vim.lsp.buf function
        vim.lsp.buf[choice]()
      else
        print("No action selected")
      end
    end)
  end
  vim.keymap.set("n", "<Leader>l", ShowLspMenu, bufopts)
end
local lspconfig = require('lspconfig')
lspconfig.clangd.setup {
  cmd = { "clangd", "--background-index" },
  filetypes = { "c", "cpp" },
  root_dir = lspconfig.util.root_pattern(".git", "compile_commands.json", "build"),
  on_attach = on_attach,
}
lspconfig.lua_ls.setup({
  settings = {
    Lua = {
      runtime = {
        version = "LuaJIT", -- Use LuaJIT for Neovim
      },
      diagnostics = {
        globals = { "vim" }, -- Recognize `vim` as a global
      },
      workspace = {
        library = vim.api.nvim_get_runtime_file("", true), -- Make LSP aware of Neovim runtime files
        checkThirdParty = false,                           -- Disable third-party check message
      },
      telemetry = {
        enable = false, -- Disable telemetry
      },
    },
  },
  on_attach = on_attach,
})
require('lualine').setup {
  options = {
    -- ... your lualine config
    theme = 'solarized'
    -- ... your lualine config
  }
}
vim.api.nvim_create_autocmd("ColorScheme", {
  pattern = "*",
  callback = function()
    vim.api.nvim_set_hl(0, "SignColumn", { link = "Normal" })
  end,
})
