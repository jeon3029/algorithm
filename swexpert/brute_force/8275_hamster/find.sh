for((i=50000;;++i)); do
    echo $i;
    ./gen $i > int
    diff -w <(./8275 < int) <(./correct < int)  ||break
done