/**************************************************************
 * 
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 * 
 *************************************************************/


#ifndef INCLUDED_MEASUREHANDLER_HXX
#define INCLUDED_MEASUREHANDLER_HXX

#include <WriterFilterDllApi.hxx>
#include <resourcemodel/LoggedResources.hxx>
#include <boost/shared_ptr.hpp>

namespace writerfilter {
namespace dmapper
{
class PropertyMap;
/** Handler for sprms that contain a measure and a unit
    - Left indent of tables
    - Preferred width of tables
 */
class WRITERFILTER_DLLPRIVATE MeasureHandler : public LoggedProperties
{
    sal_Int32 m_nMeasureValue;
    sal_Int32 m_nUnit;
    sal_Int16 m_nRowHeightSizeType; //table row height type

    // Properties
    virtual void lcl_attribute(Id Name, Value & val);
    virtual void lcl_sprm(Sprm & sprm);
    
public:
    MeasureHandler();
    virtual ~MeasureHandler();

    sal_Int32 getMeasureValue() const;
    //at least tables can have automatic width
    bool isAutoWidth() const;

    sal_Int16 GetRowHeightSizeType() const { return m_nRowHeightSizeType;}
};
typedef boost::shared_ptr
    < MeasureHandler >  MeasureHandlerPtr;
}}

#endif //
