
import java.util.Scanner;
import java.util.Stack;
import java.util.HashSet;

public class Main {

    private static int react(char[] polymer, char skip) {
        var st = new Stack<Character>();

        for (var unit : polymer) {
            var up = Character.toUpperCase(unit);
            var lo = Character.toLowerCase(unit);

            if (up == skip || lo == skip) continue;

            if (st.empty()) {
                st.push(unit);
                continue;
            }

            if (unit != st.peek() && (st.peek() == up || st.peek() == lo)) {
                st.pop();
            } else {
                st.push(unit);
            }
        }

        return st.size();
    }

    public static void main(String[] args) {
        // lend o input
        var in = new Scanner(System.in);
        char[] polymer = in.nextLine().toCharArray();
        in.close();

        // part I
        int resp = react(polymer, '-');
        System.out.println(resp);

        // part II
        int minimum = resp;
        var seen = new HashSet<Character>();
        for (var unit : polymer) {
            if (seen.contains(unit)) continue;

            seen.add(unit);
            minimum = Math.min(react(polymer, unit), minimum);
        }

        System.out.println(minimum);
    }

}
