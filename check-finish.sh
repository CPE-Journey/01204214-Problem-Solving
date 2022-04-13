total=$(ls Week*/Problems | wc -l)
done=$(ls Week*/*.cpp | wc -l)

echo "${done}/${total} Problems Completed! ($((total-done)) Remaining)"