let i = readLine()!.split(separator: " ")
let H = Int(i[0])!
let M = Int(i[1])!
var angle = Double(60 * H - 11 * M) / 2
if angle > 180 {
    angle = 360.000 - angle
}
print(angle)
