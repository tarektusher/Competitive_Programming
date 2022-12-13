```cpp
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
typedef tree<pair<ll, int> , null_type, less<pair<ll, int> >, rb_tree_tag, tree_order_statistics_node_update> ostp;//pair
typedef tree<ll,null_type,less<ll>,rb_tree_tag, tree_order_statistics_node_update> ost;//array
typedef tree<ll,null_type,less<ll>,rb_tree_tag, tree_order_statistics_node_update> ost;// Set
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag, tree_order_statistics_node_update> ost;// Multiset
///ost.order_of_key()---->Finding No. of elements smaller than X in the set
///ost.find_by_order()---->Finding the element present at the xth index in the set
