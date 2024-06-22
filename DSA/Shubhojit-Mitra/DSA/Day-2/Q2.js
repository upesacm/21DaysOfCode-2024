function climbingLeaderboard(leaderboard, player_scores) {
    // Remove duplicates from leaderboard and sort in descending order
    const uniqueLeaderboard = [...new Set(leaderboard)].sort((a, b) => b - a);
    
    // Initialize an array to hold the player's ranks
    const ranks = [];
    
    // Iterate through each of the player's scores
    player_scores.forEach(score => {
        // If the score is higher than the highest score, rank 1
        if (score >= uniqueLeaderboard[0]) {
            ranks.push(1);
        } else if (score < uniqueLeaderboard[uniqueLeaderboard.length - 1]) {
            // If the score is lower than the lowest score, rank is last
            ranks.push(uniqueLeaderboard.length + 1);
        } else {
            // Binary search to find the rank
            let low = 0;
            let high = uniqueLeaderboard.length - 1;
            while (low <= high) {
                let mid = Math.floor((low + high) / 2);
                if (uniqueLeaderboard[mid] === score) {
                    ranks.push(mid + 1);
                    break;
                } else if (uniqueLeaderboard[mid] < score) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
                // Adjust rank for scores between two leaderboard scores
                if (low > high) {
                    ranks.push(low + 1);
                }
            }
        }
    });
    
    return ranks;
}

// Example usage
const leaderboard = [100, 90, 90, 80];
const player_scores = [70, 80, 105];
console.log(climbingLeaderboard(leaderboard, player_scores)); // Output: [4, 3, 1]