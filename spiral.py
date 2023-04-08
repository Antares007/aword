import math
import turtle

# Set up initial parameters
start_x = 0
start_y = 0
radius = 10
angle = 0

# Set up turtle for drawing
t = turtle.Turtle()
t.speed(0)

# Draw the first circle
t.penup()
t.goto(start_x, start_y - radius)
t.pendown()
t.circle(radius)

# Draw the spiral
while radius < 2000:
    angle += 5
    radius += 1
    x = start_x + radius * math.cos(math.radians(angle))
    y = start_y - radius * math.sin(math.radians(angle))
    t.goto(x, y)
    t.dot(2)

# Exit gracefully
turtle.done()

