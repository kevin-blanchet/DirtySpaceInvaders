#pragma once

struct Vector2D
{
	Vector2D();

	Vector2D(const Vector2D& vector);

	Vector2D(float x, float y);

	~Vector2D() = default;

	/**
	 * \brief Check if two vector are equal if members are cast to int
	 * \param vec The vector to compare with
	 * \return True if vectors are equal, False otherise
	 */
	bool IntCmp(const Vector2D& vec);

	float x;
	float y;
};

