/*
 This example illustrates how to work with Lists and arrays in
 Reason ML.

 Author: Mrinal Aswin.

 */

/*
 In reasonML the lists are immutable. Under the hood they are simple singly-linked list.
 Please find the API reference document here: https://reasonml.github.io/api/List.html
 * Here a node 0 at the front is linked to the existing list `a`, hence calling it `b`.
 * `a` still points to [1,2,3], thus immutable
 * `b` is [0,1,2,3]
 * This is efficient since the [1,2,3] is shared.

 */

let a = [1, 2, 3];
let b = [0, ...a];

/*
  Displays 1 2 3
 */
a |> List.iter(i => Js.log({j|$i|j}));

/*
 Displays 0 1 2 3
 */
b |> List.iter(i => Js.log({j|$i|j}));

/*
  Drawback of list are that its inefficient to add something at the end.
  * operation basically takes a list of one item `[4]` and successively attaching each item of [1,2,3] to it.
  * So linear in terms of performance.
 */

let c = a @ [4];

/*
 Displays 1 2 3 4
 */
c |> List.iter(i => Js.log({j|$i|j}));

/*
  Arrays in OCaml is mutable.
  * Bucklescript compiles an ocaml array to JS array. its thus mutable and resizeable. Please find the
  API reference documentation for Js.Array here:
  https://bucklescript.github.io/bucklescript/api/Js.Array.html
 */

let d = [|1, 2, 3|];

/* Displays 1 2 3 */
d |> Array.iter(i => Js.log({j|$i|j}));

d[0] = 2;

/*
 Arrays are mutable.
 Displays 2 2 3
 */
d |> Array.iter(i => Js.log({j|$i|j}));

/*
 * Arrays can be converted to List using `Array.to_list`.
 * List can be converted to Array using `Array.of_list`.
 */

let () = Js.log(a |> Array.of_list);
let () = Js.log(d |> Array.to_list);