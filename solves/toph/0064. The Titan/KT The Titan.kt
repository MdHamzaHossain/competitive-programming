fun main() {
    var S = readln()!!.toInt()
    S++
    var sum = 0
    while (S-- > 0) {
        sum += S * S
    }
    println(sum)
}
