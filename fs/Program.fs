namespace Pe

open Pe1

module Main =
    [<EntryPoint>]
    let main argv = 
        let value = 1000
        printfn "%A" argv
        printfn "%d %d" (pe1 value) (pe1WithLoop value)
        0 // return an integer exit code
