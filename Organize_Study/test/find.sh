for((i=1;;++i)); do
    echo $i;
    ./gen $i > int
    #./correct < int > out1
    #./brute < int > out2
    #diff -w out1 out2 || break
    diff -w <(./brute < int) <(./correct < int)  ||break
done