/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function (head, n) {
    let fastNode = head;

    // Create a fastNode to traverse n steps ahead of curNode
    for (let i = 0; i < n; i++) {
        fastNode = fastNode.next;
    }

    // If the first node is the node to be removed
    if (fastNode == undefined) {
        return head.next;
    }

    let curNode = head;
    // Otherwise, traverse both nodes together until fastNode reaches the end
    while (fastNode.next) {
        curNode = curNode.next;
        fastNode = fastNode.next;
    }

    curNode.next = curNode.next.next;

    return head;
};
