namespace Pe

module Pe1 =

    let pe1 n =
        let n3 = n / 3
        let n5 = n / 5
        let n15 = n / 15
        (3 * n3 * (n3 + 1) + 5 * n5 * (n5 + 1) - 15 * n15 * (n15 + 1)) / 2

    let pe1WithLoop n =
        let mutable sum = 0
        for i = 1 to n do
            if i % 3 = 0 || i % 5 = 0 then sum <- sum + i
        sum