/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */

var reverse = function (head) {
    let previous = null, current = head, following;
    while(current) {
        following = current.next;
        current.next = previous;
        previous = current;
        current = following;
    }
    return previous;
}

/**
 * @param {ListNode} head
 * @return {void} Do not return anything, modify head in-place instead.
 */
var reorderList = function (head) {
    let head2 = findHead2(head);
    head2 = reverse(head2);

    while (head2) {
        following = head.next;
        following2 = head2.next;
        head.next = head2;
        head2.next = following;
        head2 = following2;
    }

    return head;
};
