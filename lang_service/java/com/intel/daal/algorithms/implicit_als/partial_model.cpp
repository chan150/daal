/* file: partial_model.cpp */
/*******************************************************************************
* Copyright 2014-2016 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#include <jni.h>

#include "daal.h"

#include "implicit_als/JPartialModel.h"

using namespace daal;
using namespace daal::algorithms::implicit_als;
using namespace daal::data_management;

/*
 * Class:     com_intel_daal_algorithms_implicit_als_PartialModel
 * Method:    cNewPartialModel
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_implicit_1als_PartialModel_cNewPartialModel
  (JNIEnv *env, jobject thisObj, jlong factorsAddr, jlong indicesAddr)
{
    services::SharedPtr<SerializationIface> *factorsShPtr = (services::SharedPtr<SerializationIface> *)factorsAddr;
    services::SharedPtr<SerializationIface> *indicesShPtr = (services::SharedPtr<SerializationIface> *)indicesAddr;
    services::SharedPtr<NumericTable> factors =
        services::staticPointerCast<NumericTable, SerializationIface>(*factorsShPtr);
    services::SharedPtr<NumericTable> indices =
        services::staticPointerCast<NumericTable, SerializationIface>(*indicesShPtr);
    return (jlong)(new services::SharedPtr<SerializationIface>(new PartialModel(factors, indices)));
}

/*
 * Class:     com_intel_daal_algorithms_implicit_als_PartialModel
 * Method:    cGetFactors
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_implicit_1als_PartialModel_cGetFactors
(JNIEnv *env, jobject thisObj, jlong modAddr)
{
    services::SharedPtr<SerializationIface> *factors = new services::SharedPtr<SerializationIface>();
    PartialModel *pModel = static_cast<PartialModel *>(((services::SharedPtr<SerializationIface> *)modAddr)->get());

    *factors = pModel->getFactors();

    return (jlong)factors;
}

/*
 * Class:     com_intel_daal_algorithms_implicit_als_PartialModel
 * Method:    cGetIndices
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_implicit_1als_PartialModel_cGetIndices
(JNIEnv *env, jobject thisObj, jlong modAddr)
{
    services::SharedPtr<SerializationIface> *indices = new services::SharedPtr<SerializationIface>();
    PartialModel *pModel = static_cast<PartialModel *>(((services::SharedPtr<SerializationIface> *)modAddr)->get());

    *indices = pModel->getIndices();

    return (jlong)indices;
}
