#! /bin/csh -f

# set tmpFile = `mktemp`
#echo tmpFile

set resultDir = results/
set test = 31

echo "cali|sorted" > in.txt
echo "cali|sorted" > ${resultDir}/${test}.out

rm -f ${resultDir}/${test}.err
echo "An error has occurred" > ${resultDir}/${test}.err
echo "An error has occurred" >> ${resultDir}/${test}.err
echo 0 > ${resultDir}/${test}.status

./hsh in.txt
