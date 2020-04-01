int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> basket;
    for(int i=0;i<moves.size();i++){
        int current = moves[i]-1;
        int element = 0;
        for(int h=0;h<board.size();h++){
            if(board[h][current]!=0){
                element = board[h][current];
                board[h][current]=0;
                break;
            }
        }
        if(element == 0)continue;
        if(!basket.empty()){
            int top = basket.top();
            if(element == top){
                basket.pop();
                answer+=2;
                continue;
            }
        }
        basket.push(element);
    }
    return answer;
}