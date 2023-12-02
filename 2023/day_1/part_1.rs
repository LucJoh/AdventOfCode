use std::fs;

fn main() {

	let file_path = "input.txt";

	let strings = fs::read_to_string(file_path)
		.expect("Cannot read the file");

	let strings_filtered_digits: String = strings
		.chars()
		.filter(|c| c.is_digit(10) || *c == '\n')
		.collect();

	let integers: Vec<i32> = strings_filtered_digits
		.split('\n')
		.flat_map(|s| s.parse::<i32>())
		.collect();

	for row in strings_filtered_digits.chars() {
			//let first = row.iter()
			println!("{}", row);
	}




}
