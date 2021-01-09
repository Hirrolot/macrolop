#include <epilepsy/assert.h>
#include <epilepsy/uint.h>

// E_uintInc {
E_assertEq(E_uintInc(v(0)), v(1));
E_assertEq(E_uintInc(v(15)), v(16));
E_assertEq(E_uintInc(v(198)), v(199));
E_assertEq(E_uintInc(v(1022)), v(1023));
// }

// E_uintDec {
E_assertEq(E_uintDec(v(1)), v(0));
E_assertEq(E_uintDec(v(71)), v(70));
E_assertEq(E_uintDec(v(918)), v(917));
E_assertEq(E_uintDec(v(1023)), v(1022));
// }

// E_uintEq {
E_assert(E_uintEq(v(0), v(0)));
E_assert(E_uintEq(v(18), v(18)));
E_assert(E_uintEq(v(910), v(910)));
E_assert(E_uintEq(v(1023), v(1023)));
// }

// E_uintNeq {
E_assert(E_uintNeq(v(0), v(1)));
E_assert(E_uintNeq(v(0), v(1023)));
E_assert(E_uintNeq(v(1), v(34)));
E_assert(E_uintNeq(v(184), v(1019)));
E_assert(E_uintNeq(v(603), v(16)));
// }

// E_uintGreater {
E_assert(E_uintGreater(v(1), v(0)));
// TODO: fix reaching limit. E_assert(E_uintGreater(v(1023), v(0)));
E_assert(E_uintGreater(v(5), v(4)));
E_assert(E_uintGreater(v(147), v(80)));
// TODO: fix reaching limit. E_assert(E_uintGreater(v(619), v(401)));
// }

// E_uintLesser {
E_assert(E_uintLesser(v(0), v(1)));
// TODO: fix reaching limit. E_assert(E_uintLesser(v(0), v(1023)));
E_assert(E_uintLesser(v(19), v(25)));
E_assert(E_uintLesser(v(109), v(110)));
E_assert(E_uintLesser(v(817), v(1003)));
// }

// E_uintGreaterEq {
E_assert(E_uintGreaterEq(v(0), v(0)));
E_assert(E_uintGreaterEq(v(18), v(18)));
E_assert(E_uintGreaterEq(v(175), v(175)));
E_assert(E_uintGreaterEq(v(1023), v(1023)));

E_assert(E_uintGreaterEq(v(1), v(0)));
// TODO: fix reaching limit. E_assert(E_uintGreaterEq(v(1023), v(0)));
E_assert(E_uintGreaterEq(v(19), v(10)));
// TODO: fix reaching limit. E_assert(E_uintGreaterEq(v(760), v(508)));
// }

// E_uintLesserEq {
E_assert(E_uintLesserEq(v(0), v(0)));
E_assert(E_uintLesserEq(v(2), v(2)));
E_assert(E_uintLesserEq(v(1), v(1)));
E_assert(E_uintLesserEq(v(25), v(25)));
E_assert(E_uintLesserEq(v(498), v(498)));

E_assert(E_uintLesserEq(v(0), v(1)));
// TODO: fix reaching limit. E_assert(E_uintLesserEq(v(0), v(1023)));
E_assert(E_uintLesserEq(v(18), v(27)));
E_assert(E_uintLesserEq(v(82), v(90)));
E_assert(E_uintLesserEq(v(345), v(346)));
E_assert(E_uintLesserEq(v(901), v(1023)));
// }

// E_uintAdd {

// Basic tests {
E_assertEq(E_uintAdd(v(0), v(0)), v(0));
E_assertEq(E_uintAdd(v(19), v(83)), v(19 + 83));
E_assertEq(E_uintAdd(v(8), v(4)), v(8 + 4));
// TODO: fix reaching limit. E_assertEq(E_uintAdd(v(1), v(1022)), v(1 + 1022));
// }

// Commutativity {
E_assertEq(E_uintAdd(v(1), v(2)), E_uintAdd(v(2), v(1)));
E_assertEq(E_uintAdd(v(18), v(14)), E_uintAdd(v(14), v(18)));
E_assertEq(E_uintAdd(v(181), v(30)), E_uintAdd(v(30), v(181)));
// TODO: fix reaching limit. E_assertEq(E_uintAdd(v(1), v(1022)),
// E_uintAdd(v(1022), v(1)));
// }

// Associativity {
// 0 + (1 + 2) = (0 + 1) + 2
E_assertEq(E_uintAdd(v(0), E_uintAdd(v(1), v(2))), E_uintAdd(E_uintAdd(v(0), v(1)), v(2)));

// 16 + (8 + 1) = (16 + 8) + 1
E_assertEq(E_uintAdd(v(16), E_uintAdd(v(8), v(1))), E_uintAdd(E_uintAdd(v(16), v(8)), v(1)));

// 1020 + (1 + 2) = (1020 + 1) + 2
E_assertEq(E_uintAdd(v(1020), E_uintAdd(v(1), v(2))), E_uintAdd(E_uintAdd(v(1020), v(1)), v(2)));
// }

// Identity element {
E_assertEq(E_uintAdd(v(1), v(0)), v(1));
E_assertEq(E_uintAdd(v(78), v(0)), v(78));
E_assertEq(E_uintAdd(v(256), v(0)), v(256));
E_assertEq(E_uintAdd(v(1023), v(0)), v(1023));

E_assertEq(E_uintAdd(v(0), v(1)), v(1));
E_assertEq(E_uintAdd(v(0), v(78)), v(78));
E_assertEq(E_uintAdd(v(0), v(256)), v(256));
// TODO: fix reaching limit. E_assertEq(E_uintAdd(v(0), v(1023)), v(1023));
// }

// } (E_uintAdd)

// E_uintAddVariadics {
E_assertEq(E_uintAddVariadics(v(0)), v(0));
E_assertEq(E_uintAddVariadics(v(1023)), v(1023));
// TODO: fix reaching limit. E_assertEq(E_uintAddVariadics(v(1, 2, 3, 4, 5)), v(1 + 2
// + 3 + 4 + 5));
// }

// E_uintSub {

E_assertEq(E_uintSub(v(105), v(19)), v(105 - 19));

// } (E_uintSub)

// E_uintSubVariadics {
E_assertEq(E_uintSubVariadics(v(0)), v(0));
E_assertEq(E_uintSubVariadics(v(1023)), v(1023));
// TODO: fix reaching limit. E_assertEq(E_uintSubVariadics(v(198, 13, 29, 10, 1)),
// v(198 - 13 - 29 - 10 - 1));
// }

// E_uintMul {

E_assertEq(E_uintMul(v(15), v(8)), v(15 * 8));

// } (E_uintMul)

// E_uintMulVariadics {
E_assertEq(E_uintMulVariadics(v(0)), v(0));
E_assertEq(E_uintMulVariadics(v(1023)), v(1023));
// TODO: fix reaching limit. E_assertEq(E_uintMulVariadics(v(6, 1, 9, 4)), v(6 * 1 *
// 9 * 4));
// }
