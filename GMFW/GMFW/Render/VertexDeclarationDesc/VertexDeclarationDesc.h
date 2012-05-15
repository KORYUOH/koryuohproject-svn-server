/**===File Commentary=======================================*/
/**
 *	@file	VertexDeclarationDesc.h
 *
 *	@brief	頂点データ
 *
 *	@author	KORYUOH
 *
 *	@date	2012/05/15
 */
/**===Include Guard========================================*/
#ifndef	_VERTEXDECLARATION_DESC_H_
#define	_VERTEXDECLARATION_DESC_H_
/**===File Include=========================================*/
#include	<>
/**===ENUM=================================================*/
enum VertexSemantic{
	VERTEX_SEMANTIC_POSITION				=0,
	VERTEX_SEMANTIC_BLENDWEIGHT		=1,
	VERTEX_SEMANTIC_NOMAL					=2,
	VERTEX_SEMANTIC_COLOR					=3,
	VERTEX_SEMANTIC_DIFFUSE				=4,
	VERTEX_SEMANTIC_SPECULAR				=5,
	VERTEX_SEMANTIC_TESSFATOR			=6,
	VERTEX_SEMANTIC_FOGCOORD				=7,
	VERTEX_SEMANTIC_PSIZE					=8,
	VERTEX_SEMANTIC_BLENDINDICES		=9,
	VERTEX_SEMANTIC_TEXCOORD				=10,
	VERTEX_SEMANTIC_TANGENT				=11,
	VERTEX_SEMANTIC_BINOMAL				=12
};
enum VertexType{
	VERTEX_TYPE_FLOAT				=0,
	VERTEX_TYPE_FLOAT				=1,
	VERTEX_TYPE_FLOAT				=2,
	VERTEX_TYPE_FLOAT				=3,
	VERTEX_TYPE_BYTE4				=4,
	VERTEX_TYPE_BYTE4N			=5,	
	VERTEX_TYPE_UBYTE4			=6,	
	VERTEX_TYPE_UBYTE4N			=7,	
	VERTEX_TYPE_SHORT2			=8,	
	VERTEX_TYPE_SHORT2N			=9,	
	VERTEX_TYPE_USHORT2			=10,	
	VERTEX_TYPE_USHORT2N		=11,		
	VERTEX_TYPE_SHORT4			=12,	
	VERTEX_TYPE_SHORT4N			=13,	
	VERTEX_TYPE_USHORT4			=14,	
	VERTEX_TYPE_USHORT4N		=15,
	VERTEX_TYPE_INT1				=16,
	VERTEX_TYPE_INT2				=17,
	VERTEX_TYPE_INT3				=18,
	VERTEX_TYPE_INT4				=19,
	VERTEX_TYPE_UINT1				=20,
	VERTEX_TYPE_UINT2				=21,
	VERTEX_TYPE_UINT3				=22,
	VERTEX_TYPE_UINT4				=23
};
/**========================================================*/
struct VertecDeclarationdesc{
	//セマンティック
	VertexSemantic	semantic;
	//セマンティックインデックス
	unsigned int index;
	//頂点タイプ
	VertexType type;
	//オフセット
	unsigned int offset;
	//ストリーム番号
	unsigned int stream;
}
//頂点宣言の最大値
static const unsigned int VERTEX_DECLATARION_MAX = 16;
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/