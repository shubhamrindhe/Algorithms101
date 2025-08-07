impl Solution {
    pub fn remove_subfolders(mut folders: Vec<String>) -> Vec<String> {
        folders.sort();
        let mut result = Vec::<String>::new();
        let mut directory: Option<&str> = None;

        for path in &folders {
            if directory.as_ref().map_or(false, |name| {
                path.starts_with(name) && path[name.len()..].starts_with('/')
            }) {
                continue;
            }

            directory = Some(path);
            result.push(path.clone());
        }

        result
    }
}
