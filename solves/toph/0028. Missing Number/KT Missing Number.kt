fun main() {
    var n = readln()!!.toInt()
    val a = readln()!!.split(" ")
    var res = n
    println(n - a[0].toInt() - a[1].toInt() - a[2].toInt())
}
