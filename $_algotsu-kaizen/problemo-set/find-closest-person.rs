impl Solution {
    pub fn find_closest(x: i32, y: i32, z: i32) -> i32 {
        let (dXZ, dYZ): (i32, i32) = ((z - x).abs(), (z - y).abs());
        if dXZ == dYZ { 0x0 } else { if dXZ < dYZ { 0x1 } else { 0x2 } }
    }
}
