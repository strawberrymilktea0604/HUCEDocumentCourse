#!bin/bash

# Global
n=8
TOTAL_WON=0
TOTAL_LOST=0

echo "Day la tro choi xuc xac $n mat!"

while true
do
	# generate random number 1-n
	randNum=$((RANDOM % n + 1))

	# input guess number and bet money
	read -p "Nhap so doan (1-$n) " guess
	read -p "Nhap so tien de choi: " bet

	# check valid input
	if [[ "$guess" -lt 1 || "$guess" -gt $n ]]
	then
		echo "So doan phai nam trong khoang tu 1 den $n"
		continue
	fi

	if [[ "$bet" -lt 1 ]]
	then
		echo "So tien phai lon hon 0"
		continue
	fi

	# compare 2 numbers
	if [[ "$guess" -eq "$randNum" ]]
	then
		winnings=$((bet * 10))
		echo "Chuc mung ban da thang (random=$randNum) va nhan duoc $winnings!"
		TOTAL_WON=$((TOTAL_WON + winnings))
	else
		echo "Ban da thua (random=$randNum)"
		TOTAL_LOST=$((TOTAL_LOST + bet))
	fi

	# Ask if player keep play or not
	read -p "Ban co muon choi tiep khong? (Y/N): " play_again
	if [[ "$play_again" =~ ^[Nn]$ ]]
	then
		break
	fi
done

# Print last total
echo "So tien thu duoc: $TOTAL_WON"
echo "So tien da mat: $TOTAL_LOST"
