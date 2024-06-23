leaderboard = [100, 90, 90, 80]
player_scores = [70, 80, 105]

unique_leaderboard = []
for score in leaderboard:
    if score not in unique_leaderboard:
        unique_leaderboard.append(score)

ranks = []

for score in player_scores:
    rank = 1
    previous_score = None
    for lb_score in unique_leaderboard:
        if score < lb_score and lb_score != previous_score:
            rank += 1
            previous_score = lb_score
        else:
            break
    ranks.append(rank)

print(ranks) 
