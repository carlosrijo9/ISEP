<?xml version="1.0" encoding="UTF-8"?>
<model ref="r:373d6e1c-0570-4758-801e-9091d69134c1(mealyFSM.structure)">
  <persistence version="9" />
  <languages>
    <use id="c72da2b9-7cce-4447-8389-f407dc1158b7" name="jetbrains.mps.lang.structure" version="9" />
    <use id="4caf0310-491e-41f5-8a9b-2006b3a94898" name="jetbrains.mps.execution.util" version="0" />
    <devkit ref="fbc25dd2-5da4-483a-8b19-70928e1b62d7(jetbrains.mps.devkit.general-purpose)" />
  </languages>
  <imports>
    <import index="4fqr" ref="r:fa713d69-08ea-4732-b1f2-cb07f9e103ef(jetbrains.mps.execution.util.structure)" />
    <import index="tpck" ref="r:00000000-0000-4000-0000-011c89590288(jetbrains.mps.lang.core.structure)" implicit="true" />
  </imports>
  <registry>
    <language id="c72da2b9-7cce-4447-8389-f407dc1158b7" name="jetbrains.mps.lang.structure">
      <concept id="1169125787135" name="jetbrains.mps.lang.structure.structure.AbstractConceptDeclaration" flags="ig" index="PkWjJ">
        <property id="6714410169261853888" name="conceptId" index="EcuMT" />
        <child id="1071489727083" name="linkDeclaration" index="1TKVEi" />
      </concept>
      <concept id="1169127622168" name="jetbrains.mps.lang.structure.structure.InterfaceConceptReference" flags="ig" index="PrWs8">
        <reference id="1169127628841" name="intfc" index="PrY4T" />
      </concept>
      <concept id="1071489090640" name="jetbrains.mps.lang.structure.structure.ConceptDeclaration" flags="ig" index="1TIwiD">
        <property id="1096454100552" name="rootable" index="19KtqR" />
        <reference id="1071489389519" name="extends" index="1TJDcQ" />
        <child id="1169129564478" name="implements" index="PzmwI" />
      </concept>
      <concept id="1071489288298" name="jetbrains.mps.lang.structure.structure.LinkDeclaration" flags="ig" index="1TJgyj">
        <property id="1071599776563" name="role" index="20kJfa" />
        <property id="1071599893252" name="sourceCardinality" index="20lbJX" />
        <property id="1071599937831" name="metaClass" index="20lmBu" />
        <property id="241647608299431140" name="linkId" index="IQ2ns" />
        <reference id="1071599976176" name="target" index="20lvS9" />
      </concept>
    </language>
    <language id="ceab5195-25ea-4f22-9b92-103b95ca8c0c" name="jetbrains.mps.lang.core">
      <concept id="1169194658468" name="jetbrains.mps.lang.core.structure.INamedConcept" flags="ng" index="TrEIO">
        <property id="1169194664001" name="name" index="TrG5h" />
      </concept>
    </language>
  </registry>
  <node concept="1TIwiD" id="3keuZSaMt2H">
    <property role="EcuMT" value="3823129464717037741" />
    <property role="TrG5h" value="state" />
    <ref role="1TJDcQ" to="tpck:gw2VY9q" resolve="BaseConcept" />
    <node concept="PrWs8" id="3keuZSaMt2U" role="PzmwI">
      <ref role="PrY4T" to="tpck:h0TrEE$" resolve="INamedConcept" />
    </node>
    <node concept="1TJgyj" id="4B1pGViImLa" role="1TKVEi">
      <property role="IQ2ns" value="5314642073758559306" />
      <property role="20lmBu" value="fLJjDmT/aggregation" />
      <property role="20kJfa" value="transition" />
      <property role="20lbJX" value="fLJekj5/_0__n" />
      <ref role="20lvS9" node="3keuZSaMt2I" resolve="transition" />
    </node>
  </node>
  <node concept="1TIwiD" id="3keuZSaMt2I">
    <property role="EcuMT" value="3823129464717037742" />
    <property role="TrG5h" value="transition" />
    <ref role="1TJDcQ" to="tpck:gw2VY9q" resolve="BaseConcept" />
    <node concept="PrWs8" id="3keuZSaMt2S" role="PzmwI">
      <ref role="PrY4T" to="tpck:h0TrEE$" resolve="INamedConcept" />
    </node>
    <node concept="1TJgyj" id="4B1pGViInxB" role="1TKVEi">
      <property role="IQ2ns" value="5314642073758562407" />
      <property role="20kJfa" value="event" />
      <ref role="20lvS9" node="3keuZSaMt2J" resolve="event" />
    </node>
    <node concept="1TJgyj" id="4B1pGViInxE" role="1TKVEi">
      <property role="IQ2ns" value="5314642073758562410" />
      <property role="20kJfa" value="target" />
      <ref role="20lvS9" node="3keuZSaMt2H" resolve="state" />
    </node>
    <node concept="1TJgyj" id="4B1pGViInPs" role="1TKVEi">
      <property role="IQ2ns" value="5314642073758563676" />
      <property role="20kJfa" value="action" />
      <ref role="20lvS9" node="3keuZSaMt2K" resolve="action" />
    </node>
  </node>
  <node concept="1TIwiD" id="3keuZSaMt2J">
    <property role="EcuMT" value="3823129464717037743" />
    <property role="TrG5h" value="event" />
    <ref role="1TJDcQ" to="tpck:gw2VY9q" resolve="BaseConcept" />
    <node concept="PrWs8" id="3keuZSaMt2Q" role="PzmwI">
      <ref role="PrY4T" to="tpck:h0TrEE$" resolve="INamedConcept" />
    </node>
  </node>
  <node concept="1TIwiD" id="3keuZSaMt2K">
    <property role="EcuMT" value="3823129464717037744" />
    <property role="TrG5h" value="action" />
    <ref role="1TJDcQ" to="tpck:gw2VY9q" resolve="BaseConcept" />
    <node concept="PrWs8" id="3keuZSaMt2O" role="PzmwI">
      <ref role="PrY4T" to="tpck:h0TrEE$" resolve="INamedConcept" />
    </node>
  </node>
  <node concept="1TIwiD" id="3keuZSaMt2L">
    <property role="EcuMT" value="3823129464717037745" />
    <property role="TrG5h" value="StateMachine" />
    <property role="19KtqR" value="true" />
    <ref role="1TJDcQ" to="tpck:gw2VY9q" resolve="BaseConcept" />
    <node concept="PrWs8" id="3keuZSaMt2M" role="PzmwI">
      <ref role="PrY4T" to="tpck:h0TrEE$" resolve="INamedConcept" />
    </node>
    <node concept="PrWs8" id="L$vW9UlfE8" role="PzmwI">
      <ref role="PrY4T" to="4fqr:431DWIovi3l" resolve="IMainClass" />
    </node>
    <node concept="1TJgyj" id="3keuZSaMtcf" role="1TKVEi">
      <property role="IQ2ns" value="3823129464717038351" />
      <property role="20lmBu" value="fLJjDmT/aggregation" />
      <property role="20kJfa" value="event" />
      <property role="20lbJX" value="fLJekj5/_0__n" />
      <ref role="20lvS9" node="3keuZSaMt2J" resolve="event" />
    </node>
    <node concept="1TJgyj" id="3keuZSaMtch" role="1TKVEi">
      <property role="IQ2ns" value="3823129464717038353" />
      <property role="20lmBu" value="fLJjDmT/aggregation" />
      <property role="20kJfa" value="action" />
      <property role="20lbJX" value="fLJekj5/_0__n" />
      <ref role="20lvS9" node="3keuZSaMt2K" resolve="action" />
    </node>
    <node concept="1TJgyj" id="3keuZSaMtco" role="1TKVEi">
      <property role="IQ2ns" value="3823129464717038360" />
      <property role="20lmBu" value="fLJjDmT/aggregation" />
      <property role="20kJfa" value="state" />
      <property role="20lbJX" value="fLJekj5/_0__n" />
      <ref role="20lvS9" node="3keuZSaMt2H" resolve="state" />
    </node>
    <node concept="1TJgyj" id="4B1pGViInxy" role="1TKVEi">
      <property role="IQ2ns" value="5314642073758562402" />
      <property role="20kJfa" value="intialState" />
      <property role="20lbJX" value="fLJekj4/_1" />
      <ref role="20lvS9" node="3keuZSaMt2H" resolve="state" />
    </node>
  </node>
</model>

