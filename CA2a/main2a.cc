/*This is a skeleton code file for use with the Finite Element Method for Problems in Physics.
It uses the deal.II FEM library, dealii.org*/

//Include files
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

#include "FEM2a.h"
#include "writeSolutions.h"

using namespace dealii;

//The main program, using the FEM class
int main (){
  try{
    deallog.depth_console (0);

	const int dimension = 2;

    FEM<dimension> problemObject;

	//NOTE: This is where you define the number of elements in the mesh
	std::vector<unsigned int> num_of_elems(dimension);
	num_of_elems[0] = 15;
	num_of_elems[1] = 40; //For example, a 4 x 8 element mesh in 2D

	problemObject.generate_mesh(num_of_elems);
	problemObject.setup_system();
	problemObject.assemble_system();
	problemObject.solve();
	problemObject.output_results();

    //write solutions to h5 file
    char tag[21];
    sprintf(tag, "CA2a");
    writeSolutionsToFileCA2(problemObject.D, tag);
  }
  catch (std::exception &exc){
    std::cerr << std::endl << std::endl
	      << "----------------------------------------------------"
	      << std::endl;
    std::cerr << "Exception on processing: " << std::endl
	      << exc.what() << std::endl
	      << "Aborting!" << std::endl
	      << "----------------------------------------------------"
	      << std::endl;

    return 1;
  }
  catch (...){
    std::cerr << std::endl << std::endl
	      << "----------------------------------------------------"
	      << std::endl;
    std::cerr << "Unknown exception!" << std::endl
	      << "Aborting!" << std::endl
	      << "----------------------------------------------------"
	      << std::endl;
    return 1;
  }

  return 0;
}
