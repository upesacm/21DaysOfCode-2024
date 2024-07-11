#Day2-Question2-
leaderboard_scores = []
leaderboard_scores = input("Enter the leaderboard scores in descending with the space : ").split(" ")
player_scores = []
player_scores = input("Enter the player scores with the space :").split(" ")
for i in range(len(leaderboard_scores)):
  leaderboard_scores[i] = int(leaderboard_scores[i])
for i in range(len(player_scores)):
  player_scores[i] = int(player_scores[i])  
leaderboard = []
#Remove duplicates from leaderboard_scores
for i in range(len(leaderboard_scores)):
  if leaderboard_scores[i] not in leaderboard:
    leaderboard.append(leaderboard_scores[i])  

player_rank = []

for i in range(len(leaderboard)):
  for j in range(len(player_scores)):
    if player_scores[i] >= leaderboard[j]:
      player_rank.append(j+1)
      break
    elif player_scores[i] < leaderboard[-1]:
      player_rank.append(len(leaderboard) + 1) 
      break 

print(player_rank)             
