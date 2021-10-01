bool search(Node* head, int x)
{
	Node* current = head;
	while (current != NULL)
	{
		if (current->key == x)
			return true;
		current = current->next;
	}
	return false;
}
