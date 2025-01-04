local n = 0 + io.read();
local m = 0 + io.read();
local s = ""
if n > m then
    s = "Champion\nRunner up\n"
else
    s = "Runner up\nChampion\n"
end
io.write(s);
