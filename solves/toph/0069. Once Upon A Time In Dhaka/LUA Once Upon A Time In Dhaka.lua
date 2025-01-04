local T = 0 + io.read()
while T > 0 do
    T = T - 1
    local e = {}
    for a in string.gmatch(io.read(), "[^ ]+") do
        table.insert(e, 0 + a);
    end
    io.write(string.format("%.4f", (e[1] / 2 - e[2] / 2)), "\n")
end
