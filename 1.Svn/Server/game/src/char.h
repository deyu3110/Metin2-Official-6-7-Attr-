//Find
	private:
		bool cannot_dead;
		
///Add
#if defined(__BL_67_ATTR__)
	public:
		void Open67Attr();
		void Set67Attr(bool b) { b67Attr = b; }
		bool Is67AttrOpen() const { return b67Attr; }
	private:
		bool b67Attr;
#endif