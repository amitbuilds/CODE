import java.util.*;

class Solution {
    public int countCoveredBuildings(int n, int[][] buildings) {
        // Map rows and columns to their building positions
        Map<Integer, List<Integer>> row = new HashMap<>();
        Map<Integer, List<Integer>> col = new HashMap<>();

        for (int[] b : buildings) {
            int x = b[0], y = b[1];
            row.computeIfAbsent(x, k -> new ArrayList<>()).add(y);
            col.computeIfAbsent(y, k -> new ArrayList<>()).add(x);
        }

        // Sort rows and columns
        for (List<Integer> r : row.values()) Collections.sort(r);
        for (List<Integer> c : col.values()) Collections.sort(c);

        int covered = 0;

        for (int[] b : buildings) {
            int x = b[0], y = b[1];

            List<Integer> rowList = row.get(x);
            List<Integer> colList = col.get(y);

            // Check left & right
            int yIdx = Collections.binarySearch(rowList, y);
            boolean hasLeft = yIdx > 0;
            boolean hasRight = yIdx < rowList.size() - 1;

            // Check above & below
            int xIdx = Collections.binarySearch(colList, x);
            boolean hasAbove = xIdx > 0;
            boolean hasBelow = xIdx < colList.size() - 1;

            if (hasLeft && hasRight && hasAbove && hasBelow)
                covered++;
        }

        return covered;
    }
}
