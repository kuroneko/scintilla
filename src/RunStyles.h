/** @file RunStyles.h
 ** Data structure used to store sparse styles.
 **/
// Copyright 1998-2007 by Neil Hodgson <neilh@scintilla.org>
// The License.txt file describes the conditions under which this software may be distributed.

/// Styling buffer using one element for each run rather than using
/// a filled buffer.

class RunStyles {
public:
	Partitioning *starts;
	SplitVector<int> *styles;
	int RunFromPosition(int position);
	int SplitRun(int position);
	void RemoveRun(int run);
	void RemoveRunIfEmpty(int run);
	void RemoveRunIfSameAsPrevious(int run);
public:
	RunStyles();
	~RunStyles();
	int Length();
	int ValueAt(int position);
	int FindNextChange(int position, int end);
	int StartRun(int position);
	int EndRun(int position);
	// Returns true if some values may have changed
	bool FillRange(int &position, int value, int &fillLength);
	void InsertSpace(int position, int insertLength);
	void DeleteAll();
	void DeleteRange(int position, int deleteLength);
};
