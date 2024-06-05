use rand::Rng;
use std::time::Instant;

fn main() {
    let mut rng = rand::thread_rng();
    let rounds: u32 = 10000;
    let mut keep_wins: u32 = 0;
    let mut switch_wins: u32 = 0;
    let mut random_switch_wins: u32 = 0;

    let start = Instant::now();


    for _ in 0..rounds {
        let prize_door: u32 = rng.gen_range(1..=3);
        let chosen_door: u32 = rng.gen_range(1..=3);

        if chosen_door == prize_door {
            keep_wins += 1;
        } else {
            switch_wins += 1;
        }

        if rng.gen_bool(0.5) {
            if chosen_door != prize_door {
                random_switch_wins += 1;
            }
        } else {
            if chosen_door == prize_door {
                random_switch_wins += 1;
            }
        }
    }

    let duration = start.elapsed();



    println!("Results after {} rounds:", rounds);
    println!("Keep wins: {}", keep_wins);
    println!("Keep win rate: {:.2}%", (keep_wins as f64) / (rounds as f64) * 100.0);
    println!("Switch wins: {}", switch_wins);
    println!("Switch win rate: {:.2}%", (switch_wins as f64) / (rounds as f64) * 100.0);
    println!("Random switch wins: {}", random_switch_wins);
    println!("Random switch win rate: {:.2}%", (random_switch_wins as f64) / (rounds as f64) * 100.0);

    println!("\nNotice that switch win rate is always the inverse of the keep win rate (switch_win_rate = 1 - keep_win_rate), which is roughly 66.6% of the time");
    println!("Also notice that switching on a 50/50 coin flip brings the odds of winning to 50%.\n\n");

    let duration_secs = duration.as_secs_f64();
    let duration_ns = duration.subsec_nanos();

    println!("Time taken for the simulation: ");

    if duration_secs >= 0.1 {
        println!("{} seconds", duration_secs);
    } else if duration_ns >= 100_000 {
        println!("{} milliseconds", duration_ns as f64 / 1_000_000.0);
    } else if duration_ns >= 1_000 {
        println!("{} microseconds", duration_ns as f64 / 1_000.0);
    } else {
        println!("{} nanoseconds", duration_ns);
    }

}
