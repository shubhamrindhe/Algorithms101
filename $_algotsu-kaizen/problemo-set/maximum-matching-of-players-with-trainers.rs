impl Solution {
    pub fn match_players_and_trainers(mut players: Vec<i32>, mut trainers: Vec<i32>) -> i32 {
        players.sort_by(|a, b| b.cmp(a));
        trainers.sort_by(|a, b| b.cmp(a));
        let (mut pidx, mut tidx, mut result) = (0x0, 0x0, 0x0);

        while pidx < players.len() && tidx < trainers.len() {
            if players[pidx] <= trainers[tidx] {
                result += 0x1;
                tidx += 0x1;
            }

            pidx += 0x1;
        }

        result
    }
}
