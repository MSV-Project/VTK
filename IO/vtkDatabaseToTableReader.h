/*=========================================================================

  Program:   ParaView
  Module:    $RCSfile: vtkDatabaseToTableReader.h,v $

  Copyright (c) Kitware, Inc.
  All rights reserved.
  See Copyright.txt or http://www.paraview.org/HTML/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkDatabaseToTableReader - Read an SQL table as a vtkTable
// .SECTION Description
// vtkDatabaseToTableReader reads a table from an SQL database, outputting
// it as a vtkTable.

#ifndef __vtkDatabaseToTableReader_h
#define __vtkDatabaseToTableReader_h

#include <vtkstd/string>
#include <vtkstd/vector>
#include "vtkTableReader.h"

class vtkSQLiteDatabase;
class vtkStringArray;

class VTK_IO_EXPORT vtkDatabaseToTableReader : public vtkTableReader
{
public:
  vtkTypeMacro(vtkDatabaseToTableReader,vtkTableReader);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // Set the database associated with this reader
  bool SetDatabase(vtkSQLDatabase *db);

  // Description:
  // Set the name of the table that you'd like to convert to a vtkTable
  // Returns false if the specified table does not exist in the database.
  bool SetTableName(const char *name);

  // Description:
  // Check if the currently specified table name exists in the database.
  bool CheckIfTableExists();

  vtkSQLDatabase *GetDatabase() { return this->Database; }

protected:
   vtkDatabaseToTableReader();
  ~vtkDatabaseToTableReader();
  int RequestData(vtkInformation *, vtkInformationVector **,
                          vtkInformationVector *) = 0;
  vtkSQLDatabase *Database;
  //BTX
  vtkstd::string TableName;
  //ETX
private:
  vtkDatabaseToTableReader(const vtkDatabaseToTableReader&);  // Not implemented.
  void operator=(const vtkDatabaseToTableReader&);  // Not implemented.
};

#endif