
import java.util.Scanner;

public class Main {

    static long  xo = 0, yo = 0, GCD = 0;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long  n = sc.nextLong();
        long  p = sc.nextLong();
        long  w = sc.nextLong();
        long  d = sc.nextLong();
        long  x, y, z;

        long  g = GCD(w, d);


        if (p % g != 0) {
            System.out.println("-1");
            return;
        }

        if (n * w < p) {
            // this is when he won all matches but
            // points are not equal to p
            System.out.println("-1");
            return;
        }



        y = ((p % w) * inverseModulo(d, w)) % w;
        x = (p - y * d) / w;
        if (x + y > n) {
            //if number of wins and  draw is greater than total number of matches
            System.out.println("-1");
            return;
        }

        if (x < 0) {
            System.out.println("-1");
            return;
        }

        z = n - (x + y);
        System.out.println(x + " " + y + " " + z);


    }

    private static long inverseModulo(long a, long  m) {
        if (m == 1)return 0;
        long  m0 = m, x = 1, y = 0;

        while (a > 1) {
            long  q = a / m , t = m;
            m = a % m; a = t;
            t = y;
            y = x - q * y;
            x = t;


        }

        if (x < 0) x += m0;
        return x;

    }

    private static void ExtendedEuclid(long  a, long  b) {
        //base case

        if (b == 0) {

            xo = 1;
            yo = 0;
            GCD = a;
            return;
        }

        ExtendedEuclid(b, a % b);

        long  cX = yo;
        long  cy = xo - (a / b) * yo;

        xo = cX;
        yo = cy;
    }

    private static  long GCD(long  a, long b) {
        return b == 0 ? a : GCD(b, a % b);
    }
}
