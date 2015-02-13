void Serialize(BinaryTreeNode *pRoot, ostream& stream)
{
	if (pRoot == NULL) {
		stream << "$,";
		return;
	}

	stream << pRoot->m_nValue << ",";
	Serialize(pRoot->m_pLeft, stream);
	Serialize(pRoot->m_pRight, stream);
}

void Deserialize(BinaryTreeNode **pRoot, istream& stream)
{
	int number;
	if (ReadStream(stream, &number)) {
		*pRoot = new BinaryTreeNode();
		(*pRoot)->m_nValue = number;
		(*pRoot)->m_pLeft = NULL;
		(*pRoot)->m_pRight = NULL;

		Deserialize(&(pRoot->m_pLeft), stream);
		Deserialize(&(pRoot->m_pRight), stream);
	}
}
