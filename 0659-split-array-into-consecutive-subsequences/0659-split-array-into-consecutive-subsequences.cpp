class Solution {
public:
    bool isPossible(vector<int>& nums) {
        priority_queue<conSubSeq> pq;
        for( auto &n : nums ){
            while(1){
                if( pq.empty() || n < pq.top().last() ){
                    pq.push( conSubSeq(n) );
                    break;
                }

                auto sub_seq = pq.top();
                pq.pop();

                if( n == sub_seq.last() ){
                    ++sub_seq.len;
                    pq.push( sub_seq );
                    break;
                }

                if( sub_seq.len < 3 )
                    return 0;
            }
        }

        while( pq.size() ){
            if( pq.top().len < 3 )
                return 0;
            pq.pop();
        }

        return 1;
    }

    struct conSubSeq{
    public:
        int first;
        int len;

        conSubSeq(int pos, int len = 1) : first(pos), len(len) {}

        int last() const {
            return first + len;
        }

        bool operator<( const conSubSeq& a ) const {
            if( last() == a.last() )
                return len > a.len;
            
            return last() > a.last();
        }
    };
};