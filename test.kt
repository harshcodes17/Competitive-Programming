import kotlin.math.abs
import kotlin.math.max
import kotlin.math.min

private fun readStr() = readln() // string line
private fun readInt() = readStr().toInt() // single int
private fun readStrings() = readStr().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun printLongString(s: Array<String>) = println(s.joinToString("\n")) // no flush
private fun printLongString(s: List<String>) = println(s.joinToString("\n")) // no flush

fun main() {
    
    var t = readInt()

    while (t-- > 0) {
        var s = readStr()
        var xs = s.toCharArray()
        assert(xs.size >= 2)

        var first = xs.first()
        var last = xs.last()

        var greatest = max(first.code, last.code)
        var least = min(first.code, last.code)

        var cost = abs(first.code - last.code)

        var ys = xs.mapIndexed { index, c ->
            Pair(c, index + 1)
        }.filter { it.first.code in least..greatest }
            .sortedWith(compareBy<Pair<Char, Int>> { it.first }.thenBy { it.second })

        if (first.code != least) {
            ys = ys.sortedWith(compareByDescending<Pair<Char, Int>> { it.first }.thenBy { it.second })
        }

        println("$cost ${ys.size}")
        println(ys.map { it.second }.joinToString(" "))
        
    }
}
