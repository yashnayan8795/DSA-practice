class Solution {

    public int maxCandies(int[] status, int[] candies, int[][] keys, int[][] containedBoxes, int[] initialBoxes) {
        int candiestotal=0;
        Set<Integer> visited = new HashSet<>();
        Set<Integer> foundBoxes = new HashSet<>();
        Queue<Integer> que =new LinkedList<>();

        for(int box: initialBoxes){
            foundBoxes.add(box);
            if(status[box]==1){
                que.add(box);
                visited.add(box);
                candiestotal+= candies[box];

            }
        }
        while (!que.isEmpty()) {
            int box = que.poll();

           
            for (int innerBox : containedBoxes[box]) {
                foundBoxes.add(innerBox);

                if (status[innerBox] == 1 && !visited.contains(innerBox)) {
                    que.add(innerBox);
                    visited.add(innerBox);
                    candiestotal += candies[innerBox];
                }
            }

            // Process keys
            for (int boxKey : keys[box]) {
                status[boxKey] = 1;
                if (foundBoxes.contains(boxKey) && !visited.contains(boxKey)) {
                    que.add(boxKey);
                    visited.add(boxKey);
                    candiestotal += candies[boxKey];
                }
            }
        }

        return candiestotal;
    }
}