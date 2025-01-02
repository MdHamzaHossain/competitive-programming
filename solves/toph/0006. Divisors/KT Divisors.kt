fun main() {
    var A = readln()!!.toInt()
    for (i in 1..A) {
        if (A % i == 0) {
            println(i)
        }
    }
}
