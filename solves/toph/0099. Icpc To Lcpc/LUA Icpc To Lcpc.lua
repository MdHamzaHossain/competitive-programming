n = 0 + io.read()
local s = "I have to travel back to the past"
if ((n < 1582 and n % 4 == 0) or (n % 400 == 0 or (n % 4 == 0 and n % 100 ~= 0))) then
    s = "I can participate in LCPC"
end
io.write(s, '\n')
