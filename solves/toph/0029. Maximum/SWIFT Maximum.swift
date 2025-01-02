var i = Int(readLine()!)!
var a = readLine()!.split(separator: " ")
var max = 0
while i > 0 {
    i -= 1
    if Int(a[i])! > max {
        max = Int(a[i])!
    }
}
print(max)
