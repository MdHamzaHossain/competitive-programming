local e = {}
for el in string.gmatch(io.read(), "[^ ]+") do
    table.insert(e, el)
end
local H = (0 + e[1])
local M = 0 + e[2]

local angle = (60.0 * H - 11.0 * M) / 2.00
if angle > 180.0 then
    angle = 360.0 - angle
end
io.write(angle)
