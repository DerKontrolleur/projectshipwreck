#pragma once

namespace ProjectShipwreckStructs {

	template <typename temp>
	struct Vector2D
	{
	public:
		temp X;
		temp Y;

	public:
		inline Vector2D() : X(0), Y(0) {}
		inline Vector2D(const temp& t) : X(t), Y(t) {}
		inline Vector2D(const temp& x, const temp& y) : X(x), Y(y) {}

		inline void Set(const temp& x, const temp& y) {this->X = x; this->Y = y;}


		inline Vector2D<temp> operator*(const temp& t)
		{
			return Vector2D<temp>(t * this->X, t * this->Y);
		}

		inline void operator*=(const temp& t)
		{
			this->X *= t;
			this->Y *= t;
		}

		inline Vector2D<temp> operator+(const Vector2D<temp>& v)
		{
			return Vector2D<temp>(this->X + v.X, this.Y + v.Y);
		}

		inline void operator+=(const Vector2D<temp>& v)
		{
			this->X += v.X;
			this->Y += v.Y;
		}

		inline Vector2D<temp> operator-(const Vector2D<temp>& v)
		{
			return Vector2D<temp>(this->X - v.X, this->Y - v.Y);
		}

		inline void operator-=(const Vector2D<temp>& v)
		{
			this->X -= v.X;
			this->Y -= v.Y;
		}

		inline Vector2D<temp> operator*(const Vector2D<temp>& v)
		{
			return Vector2D<temp>(this->X * v.X, this->Y * v.Y);
		}

		inline void operator*=(const Vector2D<temp>& v)
		{
			this->X *= v.X;
			this->Y *= v.Y;
		}

		inline temp Dot(const Vector2D<temp>& v1, const Vector2D<temp>& v2)
		{
			return v1.X * v2.X + v1.Y * v2.Y;
		}

		inline double GetLength()
		{
			return sqrt(pow(this->X, 2) + pow(this->Y, 2));
		}
	
		inline double GetSquareLength()
		{
			return pow(this->X, 2) + pow(this->Y, 2);
		}

		inline void Normalize()
		{
			if(this->GetSquareLength() > 0.0)
				this->Set(this->X * (1/this->GetLength()), this->Y * (1/this->GetLength()));
		}

		inline void Invert()
		{
			this->X = -this->X;
			this->Y = -this->Y;
		}
	};

	template <typename temp>
	inline ostream& operator<<(ostream& os, const Vector2D<temp>& t)
	{
		os << "X: " << t.X << " Y: " << t.Y;

		return os;
	}

	template <typename temp>
	inline ostream& operator<<(ostream& os, const Vector2D<temp>* t)
	{
		os << "X: " << t->X << " Y: " << t->Y;

		return os;
	}
}