fun main() {
    val S = (readln())
    val a = S.split(" ")
    val H = a[0].toDouble()
    val M = a[1].toDouble()
    var angle = (60.0 * H - 11.0 * M) / 2.0

    if (angle > 180.0) {
        angle = 360.000 - angle
    }
    println(angle)
}
