/******************************************************************************
* File Name : GStype.h                              Ver : 1.00  Date : 98-10-22
*
* Description :
*
*       �Q�[���V�X�e�� ��{�f�[�^�^��`�t�@�C���D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#ifndef		_GSTYPE_H_
#define		_GSTYPE_H_

#include	<windows.h>
#include	<GL/gl.h>

#pragma warning(push)
#pragma warning(disable:4201) // �����\���̂̎g�p

/****** �f�[�^�^�錾 *********************************************************/

/*----- ��{�f�[�^�^ --------------------------------------------------------*/

typedef	unsigned int	GSenum;
typedef	unsigned char	GSboolean;
typedef	unsigned int	GSbitfield;
typedef	signed char		GSbyte;
typedef	short			GSshort;
typedef	int				GSint;
typedef	int				GSsizei;
typedef	unsigned char	GSubyte;
typedef	unsigned short	GSushort;
typedef	unsigned int	GSuint;
typedef	float			GSfloat;
typedef	float			GSclampf;
typedef	double			GSdouble;
typedef	double			GSclampd;
typedef	void			GSvoid;

#define	GS_TRUE			1				/* �^ */
#define	GS_FALSE		0				/* �U */


/* �C�����C���֐��̒�` */
#ifdef __cplusplus
#define	GSINLINE	inline				/* �b�{�{ */
#else
#define	GSINLINE	static _inline		/* �b���� */
#endif

/* �b�{�{�O���Q�� */
#ifdef __cplusplus
struct GSvector2;
struct GSvector3;
struct GSvector4;
struct GSquaternion;
struct GSplane;
struct GSmatrix3;
struct GSmatrix4;
#endif



#pragma region �Q�������W�E�Q�����x�N�g���\����

/// <summary>
/// 2�������W�E2�����x�N�g���\����.
/// </summary>
typedef struct GSvector2
{
	union
	{
		struct
		{
			GSfloat		x;				/* �����W                   */
			GSfloat		y;				/* �����W                   */
		};
		struct
		{
			GSfloat		s;				/* �����W                   */
			GSfloat		t;				/* �����W                   */
		};
		GSfloat			v[2];			/* �������W                 */
	};

#ifdef __cplusplus

	/** �R���X�g���N�^ */
	GSvector2() {}
	explicit GSvector2( GSfloat X, GSfloat Y );
	explicit GSvector2( const GSvector3& v3 );
	explicit GSvector2( const GSvector4& v4 );
	explicit GSvector2( const GSfloat* p );

	/** ���K�� */
	GSvector2& normalize();

	/** ���K�������x�N�g�����擾���� */
	GSvector2 getNormalized() const;

	/** ���������߂� */
	GSfloat length() const;

	/** ���������߂� (�Q��a�̂݁j*/
	GSfloat lengthSq() const;

	/** ���������߂� */
	GSfloat distance( const GSvector2& V ) const;

	/// <summary>
	/// ���ς����߂�.
	/// <para>a�Eb = |a||b|cos��</para>
	/// </summary>
	/// <param name="V">�x�N�g��</param>
	/// <returns>���ς�Ԃ�.</returns>
	GSfloat dot( const GSvector2& V ) const;

	/** �O�ς����߂� */
	GSfloat CCW( const GSvector2& V ) const;

	/** �������v�f�����߂� */
	GSvector2 minimize( const GSvector2& V ) const;

	/** �傫���v�f�����߂� */
	GSvector2 maximize( const GSvector2& V ) const;

	/** ���`��Ԃ��s�� */
	GSvector2 lerp( const GSvector2& V, GSfloat t ) const;

	/** �Q����Ԃ��s�� */
	GSvector2 quadratic( const GSvector2& V2, const GSvector2& V3, GSfloat t ) const;

	/** ���˃x�N�g�������߂� */
	GSvector2 reflect( const GSvector2& N ) const;

	/** ���܃x�N�g�������߂� */
	GSvector2 refract( const GSvector2& N, GSfloat Eta ) const;

	/** �Q�x�N�g���̂Ȃ��p�x�����߂� */
	GSfloat degree( const GSvector2& V ) const;

	/** ���ʊp�����߂� */
	GSfloat getDirection() const;

	/** ���ʊp����x�N�g�������߂� */
	GSvector2& fromDirection( GSfloat direction );

	/** �L���X�g���Z�q�I�[�o�[���[�h */
	operator GSfloat* () const;
	operator const GSfloat* () const;

	/** �P�����Z�q�I�[�o�[���[�h */
	GSvector2  operator + () const;
	GSvector2  operator - () const;

	/** ������Z�q�I�[�o�[���[�h */
	GSvector2&  operator += ( const GSvector2& v );
	GSvector2&  operator -= ( const GSvector2& v );
	GSvector2&  operator *= ( const GSvector2& v );
	GSvector2&  operator /= ( const GSvector2& v );
	GSvector2&  operator *= ( GSfloat s );
	GSvector2&  operator /= ( GSfloat s );

	/** �Q�����Z�q�I�[�o�[���[�h */
	friend const GSvector2 operator + ( const GSvector2& v1, const GSvector2& v2 );
	friend const GSvector2 operator - ( const GSvector2& v1, const GSvector2& v2 );
	friend const GSvector2 operator * ( const GSvector2& v, const GSfloat s );
	friend const GSvector2 operator * ( const GSfloat s, const GSvector2& v );
	friend const GSvector2 operator * ( const GSmatrix3& m, const GSvector2& v );
	friend const GSvector2 operator * ( const GSvector2& v, const GSmatrix3& m );
	friend bool operator == ( const GSvector2& v1, const GSvector2& v2 );
	friend bool operator != ( const GSvector2& v1, const GSvector2& v2 );
	friend bool operator < ( const GSvector2& v1, const GSvector2& v2 );
	friend bool operator > ( const GSvector2& v1, const GSvector2& v2 );
	friend bool operator <= ( const GSvector2& v1, const GSvector2& v2 );
	friend bool operator >= ( const GSvector2& v1, const GSvector2& v2 );

#endif

} GSvector2;

#pragma endregion

#pragma region �R�������W�E�R�����x�N�g���\����

/// <summary>
/// �R�������W�E�R�����x�N�g���\����.
/// </summary>
typedef struct GSvector3
{
	union
	{
		struct
		{
			GSfloat		x;				/* �����W                   */
			GSfloat		y;				/* �����W                   */
			GSfloat		z;				/* �����W                   */
		};
		struct
		{
			GSfloat		s;				/* �����W                   */
			GSfloat		t;				/* �����W                   */
			GSfloat		p;				/* �����W                   */
		};
		struct
		{
			GSfloat		r;				/* �Ԑ���                   */
			GSfloat		g;				/* �ΐ���                   */
			GSfloat		b;				/* ����                   */
		};
		struct
		{
			GSvector2	xy;				/* �������W                 */
		};
		GSfloat			v[3];			/* ���������W               */
	};

#ifdef __cplusplus

	/** �R���X�g���N�^ */
	GSvector3() {}
	/// <summary>
	/// �R���X�g���N�^.
	/// <para>3�����x�N�g���̐���</para>
	/// </summary>
	/// <param name="X">X����</param>
	/// <param name="Y">Y����</param>
	/// <param name="Z">Z����</param>
	explicit GSvector3( GSfloat X, GSfloat Y, GSfloat Z );
	/// <summary>
	/// �R���X�g���N�^.
	/// <para>3�����x�N�g���̐���</para>
	/// </summary>
	/// <param name="v2">2�����x�N�g��</param>
	/// <param name="Z����">
	/// Z����
	/// <para>�w�肪�������0.0f</param>
	/// </param>
	explicit GSvector3( const GSvector2& v2, GSfloat Z = 0.0f );
	/// <summary>
	/// �R���X�g���N�^.
	/// <para>3�����x�N�g���̐���</para>
	/// </summary>
	/// <param name="v4">3�����x�N�g��</param>
	explicit GSvector3( const GSvector4& v4 );
	/// <summary>
	/// �R���X�g���N�^.
	/// <para>3�����x�N�g���̐���</para>
	/// </summary>
	/// <param name="p">3�����z��̃|�C���^</param>
	explicit GSvector3( const GSfloat* p );

	/// <summary>
	/// ���K��.
	/// </summary>
	GSvector3& normalize();

	/// <summary>
	/// ���K�������x�N�g�����擾����.
	/// </summary>
	GSvector3 getNormalized() const;

	/// <summary>
	/// ���������߂�.
	/// </summary>
	GSfloat length() const;

	/// <summary>
	/// ���������߂� (�Q��a�̂݁j
	/// </summary>
	GSfloat lengthSq() const;

	/// <summary>
	/// ���������߂�.
	/// </summary>
	/// <param name="V">3�����x�N�g��</param>
	GSfloat distance( const GSvector3& V ) const;

	/// <summary>
	/// ���ς����߂�.
	/// <para>a�Eb = |a||b|cos��</para>
	/// </summary>
	/// <param name="V">3�����x�N�g��</param>
	GSfloat dot( const GSvector3& V ) const;

	/// <summary>
	/// �O�ς����߂�.
	/// </summary>
	/// <param name="V">3�����x�N�g��</param>
	GSvector3 cross( const GSvector3& V ) const;

	/// <summary>
	/// �������v�f�����߂�.
	/// </summary>
	/// <param name="V">3�����x�N�g��</param>
	GSvector3 minimize( const GSvector3& V ) const;

	/// <summary>
	/// �傫���v�f�����߂�.
	/// </summary>
	/// <param name="V">3�����x�N�g��</param>
	GSvector3 maximize( const GSvector3& V ) const;

	/// <summary>
	/// ���`��Ԃ��s��.
	/// </summary>
	/// <param name="V">3�����x�N�g��</param>
	/// <param name="t">����</param>
	GSvector3 lerp( const GSvector3& V, GSfloat t ) const;

	/// <summary>
	/// �Q����Ԃ��s��.
	/// </summary>
	/// <param name="V2">3�����x�N�g��</param>
	/// <param name="V3">3�����x�N�g��</param>
	/// <param name="t">����</param>
	GSvector3 quadratic( const GSvector3& V2, const GSvector3& V3, GSfloat t ) const;

	/** ���˃x�N�g�������߂� */
	GSvector3 reflect( const GSvector3& N ) const;

	/** ���܃x�N�g�������߂� */
	GSvector3 refract( const GSvector3& N, GSfloat Eta ) const;

	/** �Q�x�N�g���̂Ȃ��p�x�����߂� */
	GSfloat degree( const GSvector3& V ) const;

	/** ���[�����߂� */
	GSfloat getYaw() const;

	/** �s�b�`�����߂� */
	GSfloat getPitch() const;

	/** �s�b�`�E���[����x�N�g�������߂� */
	GSvector3& fromPitchYaw( GSfloat picth, GSfloat yow );

	/** �@���x�N�g�������߂� */
	GSvector3 calculateNormal( const GSvector3& V1, const GSvector3& V2 ) const;

	/** �L���X�g���Z�q�I�[�o�[���[�h */
	operator GSfloat* () const;
	operator const GSfloat* () const;

	/** �P�����Z�q�I�[�o�[���[�h */
	GSvector3  operator + () const;
	GSvector3  operator - () const;

	/** ������Z�q�I�[�o�[���[�h */
	GSvector3&  operator += ( const GSvector3& v );
	GSvector3&  operator -= ( const GSvector3& v );
	GSvector3&  operator *= ( const GSvector3& v );
	GSvector3&  operator /= ( const GSvector3& v );
	GSvector3&  operator *= ( GSfloat s );
	GSvector3&  operator /= ( GSfloat s );

	/** �Q�����Z�q�I�[�o�[���[�h */
	friend const GSvector3 operator + ( const GSvector3& v1, const GSvector3& v2 );
	friend const GSvector3 operator - ( const GSvector3& v1, const GSvector3& v2 );
	friend const GSvector3 operator * ( const GSvector3& v, const GSfloat s );
	friend const GSvector3 operator * ( const GSfloat s, const GSvector3& v );
	friend const GSvector3 operator * ( const GSmatrix4& m, const GSvector3& v );
	friend const GSvector3 operator * ( const GSvector3& v, const GSmatrix4& m );
	friend const GSvector3 operator * ( const GSmatrix3& m, const GSvector3& v );
	friend const GSvector3 operator * ( const GSvector3& v, const GSmatrix3& m );
	friend bool operator == ( const GSvector3& v1, const GSvector3& v2 );
	friend bool operator != ( const GSvector3& v1, const GSvector3& v2 );
	friend bool operator < ( const GSvector3& v1, const GSvector3& v2 );
	friend bool operator > ( const GSvector3& v1, const GSvector3& v2 );
	friend bool operator <= ( const GSvector3& v1, const GSvector3& v2 );
	friend bool operator >= ( const GSvector3& v1, const GSvector3& v2 );

#endif

} GSvector3;

#pragma endregion

#pragma region �S�������W�E�S�����x�N�g���\����.

/// <summary>
/// �S�������W�E�S�����x�N�g���\����.
/// </summary>
typedef struct GSvector4
{
	union
	{
		struct
		{
			GSfloat		x;				/* �����W                   */
			GSfloat		y;				/* �����W                   */
			GSfloat		z;				/* �����W                   */
			GSfloat		w;				/* �����W                   */
		};
		struct
		{
			GSfloat		s;				/* �����W                   */
			GSfloat		t;				/* �����W                   */
			GSfloat		p;				/* �����W                   */
			GSfloat		q;				/* �����W                   */
		};
		struct
		{
			GSfloat		r;				/* �Ԑ���                   */
			GSfloat		g;				/* �ΐ���                   */
			GSfloat		b;				/* ����                   */
			GSfloat		a;				/* �A���t�@����             */
		};
		struct
		{
			GSvector2	xy;				/* �������W                 */
		};
		struct
		{
			GSvector3	xyz;			/* ���������W               */
		};
		struct
		{
			GSvector3	rgb;			/* �q�f�a                   */
		};
		GSfloat			v[4];			/* �����������W             */
	};

#ifdef __cplusplus

	/** �R���X�g���N�^ */
	GSvector4() {}
	explicit GSvector4( GSfloat X, GSfloat Y, GSfloat Z, GSfloat W );
	explicit GSvector4( const GSvector2& v2, GSfloat Z = 0.0f, GSfloat W = 0.0f );
	explicit GSvector4( const GSvector3& v3, GSfloat W = 0.0f );
	explicit GSvector4( const GSfloat* p );

	/** ���K�������x�N�g�����擾���� */
	GSvector4& normalize();

	/** ���K�������x�N�g�����擾���� */
	GSvector4 getNormalized() const;

	/** ���������߂� */
	GSfloat length() const;

	/** ���������߂� (�Q��a�̂݁j*/
	GSfloat lengthSq() const;

	/** ���������߂� */
	GSfloat distance( const GSvector4& V ) const;

	/** ���ς����߂� */
	GSfloat dot( const GSvector4& V ) const;

	/** �������v�f�����߂� */
	GSvector4 minimize( const GSvector4& V ) const;

	/** �傫���v�f�����߂� */
	GSvector4 maximize( const GSvector4& V ) const;

	/** ���`��Ԃ��s�� */
	GSvector4 lerp( const GSvector4& V, GSfloat t ) const;

	/** �Q����Ԃ��s�� */
	GSvector4 quadratic( const GSvector4& V2, const GSvector4& V3, GSfloat t ) const;

	/** �L���X�g���Z�q�I�[�o�[���[�h */
	operator GSfloat* () const;
	operator const GSfloat* () const;

	/** �P�����Z�q�I�[�o�[���[�h */
	GSvector4 operator + () const;
	GSvector4 operator - () const;

	/** ������Z�q�I�[�o�[���[�h */
	GSvector4& operator += ( const GSvector4& v );
	GSvector4& operator -= ( const GSvector4& v );
	GSvector4& operator *= ( const GSvector4& v );
	GSvector4& operator /= ( const GSvector4& v );
	GSvector4& operator *= ( GSfloat s );
	GSvector4& operator /= ( GSfloat s );

	/** �Q�����Z�q�I�[�o�[���[�h */
	friend const GSvector4 operator + ( const GSvector4& v1, const GSvector4& v2 );
	friend const GSvector4 operator - ( const GSvector4& v1, const GSvector4& v2 );
	friend const GSvector4 operator * ( const GSvector4& v, const GSfloat s );
	friend const GSvector4 operator * ( const GSfloat s, const GSvector4& v );
	friend const GSvector4 operator * ( const GSmatrix4& m, const GSvector4& v );
	friend const GSvector4 operator * ( const GSvector4& v, const GSmatrix4& m );
	friend bool operator == ( const GSvector4& v1, const GSvector4& v2 );
	friend bool operator != ( const GSvector4& v1, const GSvector4& v2 );
	friend bool operator < ( const GSvector4& v1, const GSvector4& v2 );
	friend bool operator > ( const GSvector4& v1, const GSvector4& v2 );
	friend bool operator <= ( const GSvector4& v1, const GSvector4& v2 );
	friend bool operator >= ( const GSvector4& v1, const GSvector4& v2 );

#endif

} GSvector4;

#pragma endregion


/*----- �J���[�\���� --------------------------------------------------------*/

typedef	struct GSvector4	GScolor;		/* �J���[�^			*/


#pragma region ���ʍ\����

/// <summary>
/// ���ʍ\����.
/// </summary>
typedef struct GSplane
{
	union
	{
		struct
		{
			GSfloat			a;			/* �ʖ@��������             */
			GSfloat			b;			/* �ʖ@��������             */
			GSfloat			c;			/* �ʖ@��������             */
			GSfloat			d;			/* ���_����̋���           */
		};
		struct
		{
			GSvector3		normal;		/* �ʖ@���x�N�g��           */
		};
	};

#ifdef __cplusplus

	GSplane() {}
	explicit GSplane( GSfloat A, GSfloat B, GSfloat C, GSfloat D );
	explicit GSplane( const GSvector3& N, GSfloat D );
	explicit GSplane( const GSvector3& P, const GSvector3& N );
	explicit GSplane( const GSvector3& V1, const GSvector3& V2, const GSvector3& V3 );

	/** ���K������ */
	GSplane& normalize();

	/** ���K����̕��ʂ𓾂� */
	GSplane getNormalized();

	/** ���ʏ�̈ʒu���擾 */
	GSvector3 getPoint() const;

	/** ���ʂƃx�N�g���̓��ς����߂� */
	GSfloat dot( const GSvector3& v ) const;

	/** ���ʂƓ_�̋��������߂� */
	GSfloat distance( const GSvector3& v ) const;

	/** ���ʂƐ������������邩���ׂ� */
	bool isIntersectLine( const GSvector3& Line0,  const GSvector3& Line1 ) const;

	/** ���ʂƐ����̌�_���擾���� */
	GSvector3 getIntersectLine( const GSvector3& Line0,  const GSvector3& Line1 ) const;

	/** ���ʂƐ����̌�_���擾���� */
	bool isIntersectRay( const GSvector3& Line0,  const GSvector3& Line1 ) const;

	/** ���ʂƐ����̌�_���擾���� */
	GSvector3 getIntersectRay( const GSvector3& Line0,  const GSvector3& Line1 ) const;

	/** ���ʂƍ��W�̋��������߂� */
	GSfloat getDistance( const GSvector3& p ) const;

	/** ���ʂƍ��W�̈ʒu�֌W��Ԃ� */
	GSenum getClassifyPoint( const GSvector3& p ) const;

	/** ���ʂƋ��̂̈ʒu�֌W��Ԃ� */
	GSenum getClassifyShpere( const GSvector3& center, GSfloat Radius ) const;

	/** ���`��Ԃ��s�� */
	GSplane lerp( const GSplane& V, GSfloat t ) const;

	/** �Q����Ԃ��s�� */
	GSplane quadratic( const GSplane& V2, const GSplane& V3, GSfloat t ) const;

	/** �P�����Z�q�I�[�o�[���[�h */
	GSplane  operator + () const;
	GSplane  operator - () const;

	/** �Q�����Z�q�I�[�o�[���[�h */
	friend const GSplane operator * ( const GSmatrix3& m, const GSplane& p );
	friend const GSplane operator * ( const GSplane& p, const GSmatrix3& m );
	friend const GSplane operator * ( const GSmatrix4& m, const GSplane& p );
	friend const GSplane operator * ( const GSplane& p, const GSmatrix4& m );

#endif

} GSplane;

#pragma endregion


#pragma region �N�H�[�^�j�I���\����


/// <summary>
/// �N�H�[�^�j�I���\����.
/// </summary>
typedef struct GSquaternion
{
	/// <summary>
	/// x��.
	/// <summary>
	GSfloat			x;
	/// <summary>
	/// ��.
	/// <summary>
	GSfloat			y;
	/// <summary>
	/// z��.
	/// <summary>
	GSfloat			z;
	/// <summary>
	/// �p�x.
	/// <summary>
	GSfloat			w;

#ifdef __cplusplus


	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	GSquaternion() {}
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	/// <param name="X">X��.</param>
	/// <param name="Y">Y��.</param>
	/// <param name="Z">Z��.</param>
	/// <param name="W">�p�x.</param>
	explicit GSquaternion( GSfloat X, GSfloat Y, GSfloat Z, GSfloat W );
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	/// <param name="angle">.</param>
	/// <param name="axis">.</param>
	explicit GSquaternion( GSfloat angle, const GSvector3& axis );
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	/// <param name="m">.</param>
	explicit GSquaternion( const GSmatrix3& m );
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	/// <param name="m">.</param>
	explicit GSquaternion( const GSmatrix4& m );
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	/// <param name="xAxis">.</param>
	/// <param name="yAxis">.</param>
	/// <param name="zAxis">.</param>
	explicit GSquaternion( const GSvector3& xAxis, const GSvector3& yAxis, const GSvector3& zAxis );

	/// <summary>
	/// �P�ʃN�H�[�^�j�I��������.
	/// </summary>
	GSquaternion& identity();

	/// <summary>
	/// ����.
	/// </summary>
	GSfloat dot( const GSquaternion& q ) const;

	/// <summary>
	/// ���������߂�.
	/// </summary>
	GSfloat length() const;

	/// <summary>
	/// ���K�����s��.
	/// </summary>
	GSquaternion& normalize();

	/// <summary>
	/// �t�N�H�[�^�j�I��������.
	/// </summary>
	GSquaternion& inverse();

	/// <summary>
	/// ���K����̃N�H�[�^�j�I�����擾.
	/// </summary>
	GSquaternion getNormalized() const;

	/// <summary>
	/// �t�N�H�[�^�j�I�������擾.
	/// </summary>
	GSquaternion getInverse () const;

	/// <summary>
	/// ��]�p�x����N�H�[�^�j�I����ݒ�.
	/// </summary>
	/// <param name="angle">�p�x</param>
	/// <param name="x">X��</param>
	/// <param name="y">Y��</param>
	/// <param name="z">Z��</param>
	GSquaternion& setRotate( GSfloat angle, GSfloat x, GSfloat y, GSfloat z );	 
	/// <summary>
	/// ��]�p�x����N�H�[�^�j�I����ݒ�.
	/// </summary>
	/// <param name="angle">�p�x</param>
	/// <param name="axis">��</param>
	GSquaternion& setRotate( GSfloat angle, const GSvector3& axis );

	/// <summary>
	/// ��]�p�x����N�H�[�^�j�I����ݒ�.
	/// </summary>
	/// <param name="yaw">���[</param>
	/// <param name="pitch">�s�b�`</param>
	/// <param name="roll">���[��</param>
	GSquaternion& setRotateYawPitchRoll( GSfloat yaw, GSfloat pitch, GSfloat roll );

	/// <summary>
	/// ��]�s���ݒ�.
	/// </summary>
	GSquaternion& setMatrix( const GSmatrix3& m );
	/// <summary>
	/// ��]�s���ݒ�.
	/// </summary>
	GSquaternion& setMatrix( const GSmatrix4& m );

	/** ���Ɗp�x���擾 */
	/// <summary>
	/// ���̎擾.
	/// </summary>
	GSvector3 getAxis() const;
	/// <summary>
	/// �p�x�̎擾.
	/// </summary>
	GSfloat   getAngle() const;

	/** ���[�C�s�b�`�C���[���̎擾 */
	/// <summary>
	/// ���[�̎擾.
	/// </summary>
	GSfloat getYaw() const;
	/// <summary>
	/// �s�b�`�̎擾.
	/// </summary>
	GSfloat getPitch() const;
	/// <summary>
	/// ���[���̎擾.
	/// </summary>
	GSfloat getRoll() const;

	/// <summary>
	/// ���ʐ��`���.
	/// </summary>
	GSquaternion slerp( const GSquaternion& q, GSfloat t ) const;

	/// <summary>
	/// ���`���.
	/// </summary>
	GSquaternion lerp( const GSquaternion& q, GSfloat t ) const;

	/** �P�����Z�q�I�[�o�[���[�h */
	GSquaternion operator + () const;
	GSquaternion operator - () const;

	/** ������Z�q�I�[�o�[���[�h */
	GSquaternion& operator += ( const GSquaternion& v );
	GSquaternion& operator -= ( const GSquaternion& v );
	GSquaternion& operator *= ( const GSquaternion& v );
	GSquaternion& operator *= ( GSfloat s );
	GSquaternion& operator /= ( GSfloat s );

	/** �Q�����Z�q�I�[�o�[���[�h */
	friend const GSquaternion operator + ( const GSquaternion& q1, const GSquaternion& q2 );
	friend const GSquaternion operator - ( const GSquaternion& q1, const GSquaternion& q2 );
	friend const GSquaternion operator * ( const GSquaternion& q1, const GSquaternion& q2 );
	friend const GSquaternion operator * ( const GSquaternion& q, const GSfloat s );
	friend const GSquaternion operator * ( const GSfloat s, const GSquaternion& q );
	friend bool operator == ( const GSquaternion& q1, const GSquaternion& q2 );
	friend bool operator != ( const GSquaternion& q1, const GSquaternion& q2 );

#endif

} GSquaternion;

#pragma endregion


#pragma region �R�s�R����W�ϊ��}�g���N�X�\����

/// <summary>
/// �R�s�R����W�ϊ��}�g���N�X�\����.
/// </summary>
typedef struct GSmatrix3
{
	union
	{
		/* �R�s�R��̍s��           */
		GSfloat		m[3][3];
		struct
		{
			GSfloat	_11, _12, _13;
			GSfloat	_21, _22, _23;
			GSfloat	_31, _32, _33;
		};
		GSfloat		v[9];
	};

#ifdef __cplusplus

	/// <summary>
	/// �R���X�g���N�^.
	/// <para>�R�s�R����W�ϊ��}�g���N�X�\���̂̐V�K�쐬.</para>
	/// </summary>
	GSmatrix3() {}
	/// <summary>
	/// �R���X�g���N�^.
	/// <para>�R�s�R����W�ϊ��}�g���N�X�\���̂̐V�K�쐬.</para>
	/// </summary>
	/// <param name="m11">1�s1�񐬕�</param>
	/// <param name="m12">1�s2�񐬕�</param>
	/// <param name="m13">1�s3�񐬕�</param>
	/// <param name="m21">2�s1�񐬕�</param>
	/// <param name="m22">2�s2�񐬕�</param>
	/// <param name="m23">2�s3�񐬕�</param>
	/// <param name="m31">3�s1�񐬕�</param>
	/// <param name="m32">3�s2�񐬕�</param>
	/// <param name="m33">3�s3�񐬕�</param>
	explicit GSmatrix3(
		GSfloat	m11, GSfloat m12, GSfloat m13,
		GSfloat	m21, GSfloat m22, GSfloat m23,
		GSfloat	m31, GSfloat m32, GSfloat m33 );
	/// <summary>
	/// �R���X�g���N�^.
	/// <para>�R�s�R����W�ϊ��}�g���N�X�\���̂̐V�K�쐬.</para>
	/// </summary>
	/// <param name="axisX">X��</param>
	/// <param name="axisY">Y��</param>
	/// <param name="axisZ">Z��</param>
	explicit GSmatrix3( const GSvector3& axisX,
		const GSvector3& axisY,
		const GSvector3& axisZ );
	/// <summary>
	/// �R���X�g���N�^.
	/// <para>�R�s�R����W�ϊ��}�g���N�X�\���̂̐V�K�쐬.</para>
	/// </summary>
	/// <param name="V">�����̔z��̃|�C���^</param>
	explicit GSmatrix3( const GSfloat* V );
	/// <summary>
	/// �R���X�g���N�^.
	/// <para>�R�s�R����W�ϊ��}�g���N�X�\���̂̐V�K�쐬.</para>
	/// </summary>
	/// <param name="M">�}�g���b�N�X4</param>
	explicit GSmatrix3( const GSmatrix4& M );
	/// <summary>
	/// �R���X�g���N�^.
	/// <para>�R�s�R����W�ϊ��}�g���N�X�\���̂̐V�K�쐬.</para>
	/// </summary>
	/// <param name="q">�N�H�[�^�j�I��</param>
	explicit GSmatrix3( const GSquaternion& q );

	/// <summary>
	/// �P�ʍs�񉻂���.
	/// </summary>
	GSmatrix3& identity();

	/// <summary>
	/// �g��k���s�����Z.
	/// </summary>
	GSmatrix3& scale( GSfloat x, GSfloat y, GSfloat z );
	/// <summary>
	/// �g��k���s�����Z.
	/// </summary>
	GSmatrix3& scale( const GSvector3& scaleFactor );
	/// <summary>
	/// �g��k���s�����Z.
	/// </summary>
	GSmatrix3& scale( GSfloat scaleFactor );

	/// <summary>
	/// ��]����Z.
	/// </summary>
	GSmatrix3& rotate( GSfloat angle, GSfloat axisX, GSfloat axisY, GSfloat axisZ );
	GSmatrix3& rotate( GSfloat angle, const GSvector3& axis );
	GSmatrix3& rotate( const GSquaternion& q );
	GSmatrix3& rotateX( GSfloat angle );
	GSmatrix3& rotateY( GSfloat angle );
	GSmatrix3& rotateZ( GSfloat angle );
	GSmatrix3& rotateYawPitchRoll( GSfloat yaw, GSfloat pitch, GSfloat roll );

	/** ���s�ړ�����Z */
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	GSmatrix3& translate( GSfloat x, GSfloat y );
	GSmatrix3& translate( const GSvector2& translation );

	/** �t�s��ɂ��� */
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	GSmatrix3& inverse();

	/** �]�u�s��ɂ��� */
	GSmatrix3& transpose();

	/** �]�u�t�s��ɂ��� */
	GSmatrix3& inverseTranspose();

	/** �t�s����擾 */
	GSmatrix3 getInverse() const;

	/** �]�u�s����擾 */
	GSmatrix3 getTranspose() const;

	/** �]�u�t�s����擾 */
	GSmatrix3 getInverseTranspose() const;

	/** �X�P�[���l�̐ݒ� */
	GSmatrix3& setScale( GSfloat x, GSfloat y, GSfloat z );
	GSmatrix3& setScale( const GSvector3& scaleFactor );
	GSmatrix3& setScale( GSfloat scaleFactor );

	/** ��]�p�x�̐ݒ� */
	GSmatrix3& setRotation( GSfloat angle, GSfloat axisX, GSfloat axisY, GSfloat axisZ );
	GSmatrix3& setRotation( GSfloat angle, const GSvector3& axis );
	GSmatrix3& setRotation( const GSquaternion& q );
	GSmatrix3& setRotationX( GSfloat angle );
	GSmatrix3& setRotationY( GSfloat angle );
	GSmatrix3& setRotationZ( GSfloat angle );
	GSmatrix3& setRotationYawPitchRoll( GSfloat yaw, GSfloat pitch, GSfloat roll );

	/** ���s�ړ��ʂ̐ݒ� */
	GSmatrix3& setTranslation( GSfloat x, GSfloat y );
	GSmatrix3& setTranslation( const GSvector2& translation );

	/** ���W�ϊ� */
	GSvector2 transform( const GSvector2& v ) const;
	GSvector3 transform( const GSvector3& v ) const;
	GSplane   transform( const GSplane& p ) const;
	GSvector2 transformNormal( const GSvector2& v ) const;

	/** ���C�ʒu�̐ݒ� */
	GSmatrix3& setAxisX( const GSvector3& axisX );
	GSmatrix3& setAxisY( const GSvector3& axisY );
	GSmatrix3& setAxisZ( const GSvector3& axisZ );

	/** ���[���E�s�b�`�E���[�̎擾 */
	GSfloat getRoll() const;
	GSfloat getPitch() const;
	GSfloat getYaw() const;
	void setPosition( const GSvector2& position );

	/** �N�H�[�^�j�I�����擾 */
	GSquaternion getQuaternion() const;

	/** ���C�ʒu�̎擾 */
	GSvector3 getAxisX() const;
	GSvector3 getAxisY() const;
	GSvector3 getAxisZ() const;
	GSvector2 getPosition() const;

	/** �L���X�g���Z�q�I�[�o�[���[�h */
	operator GSfloat* () const;
	operator const GSfloat* () const;

	/** �P�����Z�q�I�[�o�[���[�h */
	GSmatrix3 operator + () const;
	GSmatrix3 operator - () const;

	/** ������Z�q�I�[�o�[���[�h */
	GSmatrix3& operator += ( const GSmatrix3& v );
	GSmatrix3& operator -= ( const GSmatrix3& v );
	GSmatrix3& operator *= ( const GSmatrix3& v );
	GSmatrix3& operator *= ( GSfloat s );
	GSmatrix3& operator /= ( GSfloat s );

	/** �Q�����Z�q�I�[�o�[���[�h */
	friend const GSmatrix3 operator + ( const GSmatrix3& m1, const GSmatrix3& m2 );
	friend const GSmatrix3 operator - ( const GSmatrix3& m1, const GSmatrix3& m2 );
	friend const GSmatrix3 operator * ( const GSmatrix3& m1, const GSmatrix3& m2 );
	friend const GSmatrix3 operator * ( const GSmatrix3& m, const GSfloat s );
	friend const GSmatrix3 operator * ( const GSfloat s, const GSmatrix3& m );
	friend bool operator == ( const GSmatrix3& v1, const GSmatrix3& v2 );
	friend bool operator != ( const GSmatrix3& v1, const GSmatrix3& v2 );

#endif

} GSmatrix3;

#pragma endregion


#pragma region �S�s�S����W�ϊ��}�g���N�X�\����


/// <summary>
/// �S�s�S����W�ϊ��}�g���N�X�\����.
/// </summary>
typedef struct GSmatrix4
{
	union
	{
		/* �S�s�S��̍s��           */
		GSfloat		m[4][4];
		struct
		{
			GSfloat	_11, _12, _13, _14;
			GSfloat	_21, _22, _23, _24;
			GSfloat	_31, _32, _33, _34;
			GSfloat	_41, _42, _43, _44;
		};
		GSfloat		v[16];
	};

#ifdef __cplusplus

	/** �R���X�g���N�^ */
	GSmatrix4() {}
	explicit GSmatrix4(
		GSfloat	m11, GSfloat m12, GSfloat m13, GSfloat m14,
		GSfloat	m21, GSfloat m22, GSfloat m23, GSfloat m24,
		GSfloat	m31, GSfloat m32, GSfloat m33, GSfloat m34,
		GSfloat	m41, GSfloat m42, GSfloat m43, GSfloat m44  );
	explicit GSmatrix4(
		const GSvector4& axisX,
		const GSvector4& axisY,
		const GSvector4& axisZ,
		const GSvector4& position );
	explicit GSmatrix4( const GSfloat* V );
	explicit GSmatrix4( const GSmatrix3& M );
	explicit GSmatrix4( const GSquaternion& q );

	/** �P�ʍs�񉻂��� */
	GSmatrix4& identity();

	/** �g��k���s�����Z */
	GSmatrix4& scale( GSfloat x, GSfloat y, GSfloat z );
	GSmatrix4& scale( const GSvector3& scaleFactor );
	GSmatrix4& scale( GSfloat scaleFactor );

	/** ��]����Z */
	GSmatrix4& rotate( GSfloat angle, GSfloat axisX, GSfloat axisY, GSfloat axisZ );
	GSmatrix4& rotate( GSfloat angle, const GSvector3& axis );
	GSmatrix4& rotate( const GSquaternion& q );
	GSmatrix4& rotateX( GSfloat angle );
	GSmatrix4& rotateY( GSfloat angle );
	GSmatrix4& rotateZ( GSfloat angle );
	GSmatrix4& rotateYawPitchRoll( GSfloat yaw, GSfloat pitch, GSfloat roll );

	/** ���s�ړ�����Z */
	GSmatrix4& translate( GSfloat x, GSfloat y, GSfloat z );
	GSmatrix4& translate( const GSvector3& translation );

	/** �t�s��ɂ��� */
	GSmatrix4& inverse();

	/** �t�s��ɂ��� */
	GSmatrix4& inverseFast();

	/** �]�u�s��ɂ��� */
	GSmatrix4& transpose();

	/** �]�u�t�s��ɂ��� */
	GSmatrix4& inverseTranspose();

	/** �t�s����擾 */
	GSmatrix4 getInverse() const;

	/** �t�s����擾 */
	GSmatrix4 getInverseFast() const;

	/** �]�u�s����擾 */
	GSmatrix4 getTranspose() const;

	/** �]�u�t�s����擾 */
	GSmatrix4 getInverseTranspose() const;

	/** �X�P�[���l�̐ݒ� */
	GSmatrix4& setScale( GSfloat x, GSfloat y, GSfloat z );
	GSmatrix4& setScale( const GSvector3& scaleFactor );
	GSmatrix4& setScale( GSfloat scaleFactor );

	/** ��]�p�x�̐ݒ� */
	GSmatrix4& setRotation( GSfloat angle, GSfloat axisX, GSfloat axisY, GSfloat axisZ );
	GSmatrix4& setRotation( GSfloat angle, const GSvector3& axis );
	GSmatrix4& setRotation( const GSquaternion& q );
	GSmatrix4& setRotationX( GSfloat angle );
	GSmatrix4& setRotationY( GSfloat angle );
	GSmatrix4& setRotationZ( GSfloat angle );
	GSmatrix4& setRotationYawPitchRoll( GSfloat yaw, GSfloat pitch, GSfloat roll );

	/** ���s�ړ��ʂ̐ݒ� */
	GSmatrix4& setTranslation( GSfloat x, GSfloat y, GSfloat z );
	GSmatrix4& setTranslation( const GSvector3& translation );

	/** �����ϊ��s��̐ݒ� */
	GSmatrix4& setPerspectiveRH( GSfloat fovy, GSfloat aspect, GSfloat n, GSfloat f );
	GSmatrix4& setPerspectiveLH( GSfloat fovy, GSfloat aspect, GSfloat n, GSfloat f );
	GSmatrix4& setFrustumRH( GSfloat left, GSfloat right, GSfloat bottom, GSfloat top, GSfloat n, GSfloat f );
	GSmatrix4& setFrustumLH( GSfloat left, GSfloat right, GSfloat bottom, GSfloat top, GSfloat n, GSfloat f );
	GSmatrix4& setOrthoRH( GSfloat left, GSfloat right, GSfloat bottom, GSfloat top, GSfloat n = -1.0f, GSfloat f = 1.0f );
	GSmatrix4& setOrthoLH( GSfloat left, GSfloat right, GSfloat bottom, GSfloat top, GSfloat n = -1.0f, GSfloat f = 1.0f );

	/** ����ϊ��s��̐ݒ� */
	GSmatrix4& setLookAtRH( GSfloat fromX, GSfloat formY, GSfloat formZ,
		GSfloat atX,   GSfloat atY,   GSfloat atZ,
		GSfloat upX,   GSfloat upY,   GSfloat upZ );
	GSmatrix4& setLookAtRH( const GSvector3& from, const GSvector3& at, const GSvector3& up );
	GSmatrix4& setLookAtLH( GSfloat fromX, GSfloat formY, GSfloat formZ,
		GSfloat atX,   GSfloat atY,   GSfloat atZ,
		GSfloat upX,   GSfloat upY,   GSfloat upZ );
	GSmatrix4& setLookAtLH( const GSvector3& from, const GSvector3& at, const GSvector3& up );

	/** ����ϊ��s��ɕϊ����� */
	GSmatrix4& convertViewRH();
	GSmatrix4& convertViewLH();

	/** �n���ʃV���h�E�}�g���N�X�̐ݒ� */
	GSmatrix4& setShadow( const GSplane& plane, const GSvector3& lightPosition );

	/** ���W�ϊ� */
	GSvector2 transform( const GSvector2& v ) const;
	GSvector3 transform( const GSvector3& v ) const;
	GSvector4 transform( const GSvector4& v ) const;
	GSplane   transform( const GSplane& p ) const;
	GSvector2 transformCoord( const GSvector2& v ) const;
	GSvector3 transformCoord( const GSvector3& v ) const;
	GSvector4 transformCoord( const GSvector4& v ) const;
	GSvector3 transformNormal( const GSvector3& v ) const;

	/** ���C�ʒu�̐ݒ� */
	GSmatrix4& setAxisX( const GSvector3& axisX );
	GSmatrix4& setAxisY( const GSvector3& axisY );
	GSmatrix4& setAxisZ( const GSvector3& axisZ );
	GSmatrix4& setPosition( const GSvector3& position );

	/** ���[���E�s�b�`�E���[�̎擾 */

	/// <summary>
	/// ���[���̎擾.
	/// <para>Z������̉�]</para>
	/// </summary>
	/// <returns>���[���l</returns>
	GSfloat getRoll() const;
	/// <summary>
	/// �s�b�`�̎擾.
	/// <para>X������̉�]</para>
	/// </summary>
	/// <returns>�s�b�`�l</returns>
	GSfloat getPitch() const;
	/// <summary>
	/// ���[�̎擾.
	/// <para>Y������̉�]</para>
	/// </summary>
	/// <returns>���[�l</returns>
	GSfloat getYaw() const;

	/** �N�H�[�^�j�I�����擾 */
	GSquaternion getQuaternion() const;

	/** ���C�ʒu�̎擾 */
	GSvector3 getAxisX() const;
	GSvector3 getAxisY() const;
	GSvector3 getAxisZ() const;
	GSvector3 getPosition() const;

	/** �L���X�g���Z�q�I�[�o�[���[�h */
	operator GSfloat* () const;
	operator const GSfloat* () const;

	/** �P�����Z�q�I�[�o�[���[�h */
	GSmatrix4 operator + () const;
	GSmatrix4 operator - () const;

	/** ������Z�q�I�[�o�[���[�h */
	GSmatrix4& operator += ( const GSmatrix4& v );
	GSmatrix4& operator -= ( const GSmatrix4& v );
	GSmatrix4& operator *= ( const GSmatrix4& v );
	GSmatrix4& operator *= ( GSfloat s );
	GSmatrix4& operator /= ( GSfloat s );

	/** �Q�����Z�q�I�[�o�[���[�h */
	friend const GSmatrix4 operator + ( const GSmatrix4& m1, const GSmatrix4& m2 );
	friend const GSmatrix4 operator - ( const GSmatrix4& m1, const GSmatrix4& m2 );
	friend const GSmatrix4 operator * ( const GSmatrix4& m1, const GSmatrix4& m2 );
	friend const GSmatrix4 operator * ( const GSmatrix4& m, const GSfloat s );
	friend const GSmatrix4 operator * ( const GSfloat s, const GSmatrix4& m );
	friend bool operator == ( const GSmatrix4& v1, const GSmatrix4& v2 );
	friend bool operator != ( const GSmatrix4& v1, const GSmatrix4& v2 );

#endif

} GSmatrix4;

#pragma endregion


#pragma region ��`�\����

/// <summary>
/// ��`�\����.
/// </summary>
typedef struct GSrect
{
	GSfloat			left;			/* ������̂����W           */
	GSfloat			top;			/* ������̂����W           */
	GSfloat			right;			/* �E�����̂����W           */
	GSfloat			bottom;			/* �E�����̂����W           */

#ifdef __cplusplus
	/** �R���X�g���N�^ */
	GSrect( GSfloat l = 0, GSfloat t = 0, GSfloat r = 0, GSfloat b = 0 ) :
		left( l ), top( t ), right( r ), bottom( b )
	{}
#endif

} GSrect;

#pragma endregion


#pragma region �J���[�^

/// <summary>
/// �J���[�^.
/// </summary>
typedef	GSvector4	GScolor4;

#pragma endregion




#pragma warning(pop)

#endif

/********** End of File ******************************************************/
