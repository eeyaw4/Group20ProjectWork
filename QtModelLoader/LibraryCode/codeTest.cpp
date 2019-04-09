#include "catch.hpp"
#include "Model.h"

TEST_CASE( "Model Library Test", "[ModelClass]" ) {
	SECTION ("Loading A Material From The Model File"){
		Model testModel;
		testModel.readFile("../ExampleModel1.mod");

		testModel.getMaterialData(0);

		REQUIRE( testModel.materialID == 0 );
		REQUIRE( testModel.materialDensity == 8960 );
		REQUIRE( testModel.materialColour == "b87333" );
		REQUIRE( testModel.materialName == "copper" );
	}

	SECTION ("Loading A Vertex From The Model File"){
		Model testModel;
		testModel.readFile("../ExampleModel1.mod");

		testModel.getVertexData(6);

		vector<float> testVector;

		testVector.push_back(1.);
		testVector.push_back(1.);
		testVector.push_back(1.);

		REQUIRE( testModel.vertexID == 6 );
		REQUIRE( testModel.vertexXYZ == testVector );
	}

	SECTION ("Loading A Cell From The Model File"){
		Model testModel;
		testModel.readFile("../ExampleModel1.mod");

		testModel.getCellData(1);

		REQUIRE( testModel.cellID == 1 );
		REQUIRE( testModel.cellShape == "t" );
		REQUIRE( testModel.cellMaterial == 1 );
	}
}