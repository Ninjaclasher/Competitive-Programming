import java.io.*;
import java.util.*;

public class evanscube
{
    public static char[][][] cube = new char[6][3][3];

    public static void rotateFace(int face)
    {
        char[][] tmp = new char[3][3];
        for (int x = 0; x < 3; x++)
            for (int y = 0; y < 3; y++)
                tmp[y][2-x] = cube[face][x][y];
        for (int x = 0; x < 3; x++)
            for (int y = 0; y < 3; y++)
                cube[face][x][y] = tmp[x][y];
    }

    public static char[] getStrip(int face, int[] positions)
    {
        char[] ret = new char[3];
        for (int x = 0; x < 3; x++)
            ret[x] = cube[face][positions[x] / 3][positions[x] % 3];
        return ret;
    }

    public static void fillStrip(int face, int[] positions, char[] arr)
    {
        for (int x = 0; x < 3; x++)
            cube[face][positions[x] / 3][positions[x] % 3] = arr[x];
    }

    public static void rotateStrip(int f1, int[] p1, int f2, int[] p2, int f3, int[] p3, int f4, int[] p4)
    {
        char[] tmp = getStrip(f1, p1);
        fillStrip(f1, p1, getStrip(f4, p4));
        fillStrip(f4, p4, getStrip(f3, p3));
        fillStrip(f3, p3, getStrip(f2, p2));
        fillStrip(f2, p2, tmp);
    }

    public static void main(String[] args) throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        for (int x = 0; x < 6; x++)
        {
            for (int y = 0; y < 3; y++)
            {
                String tmp = in.readLine();
                for (int z = 0; z < 3; z++)
                    cube[x][y][z] = tmp.charAt(z);
            }
        }
        int q = Integer.parseInt(in.readLine());
        while (q-->0)
        {
            String tmp = in.readLine();
            int face = (int)(tmp.charAt(0) - '1');
            char dir = tmp.charAt(1);
            // clockwise rotations
            for (int iter = 0; iter < (dir == 'C' ? 1 : 3); iter++)
            {
                rotateFace(face);
                switch(face)
                {
                    case 0:
                        // always clockwise around the face being rotated
                        rotateStrip(
                            5,
                            new int[]{2,1,0},
                            3,
                            new int[]{0,3,6},
                            4,
                            new int[]{2,1,0},
                            1,
                            new int[]{8,5,2}
                        );
                        break;
                    case 1:
                        rotateStrip(
                            5,
                            new int[]{8,5,2},
                            0,
                            new int[]{0,3,6},
                            4,
                            new int[]{0,3,6},
                            2,
                            new int[]{8,5,2}
                        );
                        break;
                    case 2:
                        rotateStrip(
                            5,
                            new int[]{6,7,8},
                            1,
                            new int[]{0,3,6},
                            4,
                            new int[]{6,7,8},
                            3,
                            new int[]{8,5,2}
                        );
                        break;
                    case 3:
                        rotateStrip(
                            5,
                            new int[]{0,3,6},
                            2,
                            new int[]{0,3,6},
                            4,
                            new int[]{8,5,2},
                            0,
                            new int[]{8,5,2}
                        );
                        break;
                    case 4:
                        rotateStrip(
                            0,
                            new int[]{6,7,8},
                            3,
                            new int[]{6,7,8},
                            2,
                            new int[]{6,7,8},
                            1,
                            new int[]{6,7,8}
                        );
                        break;
                    case 5:
                        rotateStrip(
                            0,
                            new int[]{2,1,0},
                            1,
                            new int[]{2,1,0},
                            2,
                            new int[]{2,1,0},
                            3,
                            new int[]{2,1,0}
                        );
                        break;
                }
            }
        }
        for (int face = 0; face < 6; face++)
        {
            char col = cube[face][0][0];
            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    if (cube[face][x][y] != col)
                    {
                        System.out.println("Boo!");
                        return;
                    }
                }
            }
        }
        System.out.println("Solved!");
    }
}
