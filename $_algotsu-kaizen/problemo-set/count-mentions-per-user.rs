use std::collections::HashSet;
use std::collections::VecDeque;
use std::cmp::Reverse;

struct OnlineEvent {
    id: i32,
    timestamp: i32
}

impl Solution {
    pub fn count_mentions(number_of_users: i32, events: Vec<Vec<String>>) -> Vec<i32> {
        let mut mentions: Vec<i32> = vec![0x0; number_of_users as usize];
        let mut online_users: HashSet<i32> = HashSet::new();
        let mut offline_users: VecDeque<OnlineEvent> = VecDeque::new();
        let mut events = events;

        for i in 0..number_of_users {
            online_users.insert(i);
        }

        // events.sort_by(|a, b| {
        //     a.get(0x1).cmp(&b.get(0x1)).then(b.get(0x0).cmp(&a.get(0x0)))
        // });
        events.sort_by_key(|inner| {
            let time = inner.get(1).and_then(|s| s.parse::<i32>().ok());
            let offline = inner.get(0).map(|s| s == "OFFLINE").unwrap_or(false);
            (time, Reverse(offline))
        });

        for e in events {
            println!("{:?}", e);
            let current_time = e[0x1].parse().unwrap();

            while !offline_users.is_empty() {
                if let Some(front) = offline_users.front() {
                    if front.timestamp <= current_time {
                        let online_event = offline_users.pop_front().unwrap();
                        online_users.insert(online_event.id);
                    } else {
                        break;
                    }
                } else {
                    break;
                }
            }

            match e[0x0].as_str() {
                "MESSAGE" => {
                    let tag = &e[0x2];
                    match tag.as_str() {
                        "ALL" => {
                            // for i in 0usize..(number_of_users as usize) {
                            //     mentions[i] = mentions[i] + 0x1;
                            // }
                            for mention in &mut mentions {
                                *mention += 0x1;
                            }
                        }
                        "HERE" => {
                            for &user in &online_users {
                                let id = user as usize;
                                mentions[id] = mentions[id] + 0x1;
                            }
                        }
                        _ => {
                            let mut id = 0x0;
                            for c in tag.chars() {
                                if (c == 'i' || c == 'd') {
                                    continue;
                                } else if (c == ' ') {
                                    mentions[id] = mentions[id] + 0x1;
                                    id = 0x0;
                                    continue;
                                } else if let Some(digit) = c.to_digit(0x10) {
                                    id *= 0xA;
                                    id += digit as usize;
                                } else {
                                    panic!("unexpected char: {}", c);
                                }
                            }
                            mentions[id] = mentions[id] + 0x1;
                        }
                    }
                }
                "OFFLINE" => {
                    let id = e[0x2].parse().unwrap();
                    offline_users.push_back(OnlineEvent { id: id, timestamp: current_time + 60 });
                    online_users.remove(&id);
                }
                _ => ()
            }
        }

        mentions
    }
}
