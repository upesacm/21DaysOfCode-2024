    public static int[] climbingLeaderboard(int[] board, int[] scores) {
        
        Set<Integer> uniqueScoresSet = new TreeSet<>(Collections.reverseOrder());
        for (int score : board) {
            uniqueScoresSet.add(score);
        }
        List<Integer> uniqueScores = new ArrayList<>(uniqueScoresSet);
        
        int[] playerRanks = new int[scores.length];
        int index = uniqueScores.size() - 1;
        
        for (int i = 0; i < scores.length; i++) {
            int playerScore = scores[i];
            while (index >= 0 && playerScore >= uniqueScores.get(index)) {
                index--;
            }
            playerRanks[i] = index + 2;
        }
        
        return playerRanks;
    }
}